/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_crop_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:51:46 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 23:06:42 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_methods.h"
#include "misc_methods.h"

t_itree *file_crop_text(t_itable **list, t_itree *T, int t, char *filename, char *str, int max_len)
{
	int remaining_size;
	char	*str_ptr, *holder, *content;
	t_db	*this_id_db, *next_id_db, *result;
	
	content = NULL;
	result = NULL;
	remaining_size = 0;
	result = file_search(list, T, filename, str);
	if(!result)
		return (T);	
	str_ptr = ft_strnstr(result->content, str, strlen(result->content));
	if(str_ptr)
	{		
		holder = str_ptr + strlen(str);
		while(holder[remaining_size++]);
		memmove(str_ptr, (str_ptr + strlen(str)), (remaining_size + 1));
	}
	else
	{
		this_id_db = ibt_get_db_by_id(T, result->id);
		next_id_db = ibt_get_db_by_id(T, result->next_id);
		content = ft_strjoin(this_id_db->content, next_id_db->content);
		str_ptr = ft_strnstr(content, str, strlen(content));
		holder = str_ptr + strlen(str);
		while(holder[remaining_size++]);
		memmove(str_ptr, (str_ptr + strlen(str)), (remaining_size + 1));
		free(this_id_db->content);
		free(next_id_db->content);
		this_id_db->content = ft_substr(content, 0, max_len);
		next_id_db ->content = ft_substr(content, max_len, max_len);
	}
	if(!strlen(result->content))
	{
		if(result->id == (it_search(*list, filename))->id)
		{
			if(result->next_id == -1)
				it_remove(list, it_search(*list, filename));
			else
				it_search(*list, filename)->id = result->next_id;
		}				
		T = ibt_remove(T, result, t);		
	}		
	return (T);
}