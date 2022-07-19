/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_crop_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:51:46 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/18 22:46:51 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_methods.h"
#include "misc_methods.h"

static int min(int x, int y)
{
	if(x <= y)
		return (x);
	return(y);
}

static char *search_str_start(char *db_content, char *str)
{
	unsigned int	i, h_iter;
	char			*s_ptr;

	h_iter = 0;
	while (db_content[h_iter])
	{		
		if (db_content[h_iter] == str[0])
		{
			i = 0;
			s_ptr = &db_content[h_iter];			
			while (str[i] && s_ptr[i] == str[i])
				i++;
			if (!str[i])
				return (s_ptr);
		}
		h_iter++;
	}
	return (s_ptr);
}

static char *search_str_end(t_itree *T, t_db *db_start, t_db **db_end, char *str, char *str_start)
{
	unsigned int	total_size, i, j;
	char			*str_end;
	t_db			*db_holder;

	i = 0;
	j = 0;
	str_end = str_start;
	db_holder = db_start;
	total_size = strlen(str);	
	while(i < total_size)
	{
		i++;
		j++;
		if(!str_end[j])
		{
			if(i == total_size)
			{
				*db_end = db_holder;
				return (&str_end[j]);
			}				
			j = 0;
			db_holder = ibt_get_db_by_id(T, db_holder->next_id);
			str_end = db_holder->content;			
		}
	}
	*db_end = db_holder;
	return (&str_end[j]);
}

static t_itree *file_crop_aux(t_itree *T, int id, char *str, int t)
{
	int		crop_size, db_end_size;
	t_db	*db_start, *db_end, *empty;
	char	*str_start, *str_end;

	crop_size = 0;
	db_end_size = 0;
	db_start = ibt_get_db_by_id(T, id);
	str_start = search_str_start(db_start->content, str);
	str_end = search_str_end(T, db_start, &db_end, str, str_start);
	while(str_start[crop_size])
		crop_size++;
	memmove(str_start, str_end, crop_size);
	if(db_start != db_end)
	{
		while(str_start[db_end_size])
			db_end_size++;
		(db_end->content) = str_end + min(db_end_size, crop_size);
		while(db_start->next_id != db_end->id)
		{
			empty = ibt_get_db_by_id(T, db_start->next_id);
			if(ibt_get_db_by_id(T, empty->next_id))
				ibt_get_db_by_id(T, empty->next_id)->previous_id = db_start->id;
			db_start->next_id = empty->next_id;
			T = ibt_remove(T, empty, t);
		}
	}		
	return (T);
}

t_itree *file_crop_text(t_itable **list, t_itree *T, int t, char *filename, char *str, int max_len)
{
	t_db		*str_start_db;

	str_start_db = file_search(list, T, filename, str);
    if(str_start_db)
	{
		T = file_crop_aux(T, str_start_db->id, str, t);
		T = ibt_reorganize_content(T, str_start_db->id, t, (size_t) max_len);
		if(!strlen(str_start_db->content))
		{
			T = ibt_remove(T, str_start_db, t);	
			it_remove(list, it_search(*list, filename));
		}
				
		return (T);
	}		
	return (T);
}