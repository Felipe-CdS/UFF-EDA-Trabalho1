/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:20:21 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/16 13:00:36 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_methods.h"

/*
*	Searchs for a needle in a haystack;
*	h_*: Haystack vars;
*	n_*: Needle vars;
*/

static int	check_needle(t_itree *T, int id, char *n_ptr, char *s_ptr)
{
	unsigned int	n_i;
	unsigned int	s_i;
	t_db 			*holder;

	n_i = 0;
	s_i = 0;
	holder = ibt_get_db_by_id(T, id);
	while (s_ptr[s_i] == n_ptr[n_i])
	{
		s_i++;
		n_i++;
		if (!n_ptr[n_i])
			return (1); // Str found;
		if(!s_ptr[s_i])
		{
			if(holder->next_id == -1)
				return (EOF);
			s_i = 0;
			holder = ibt_get_db_by_id(T, holder->next_id);
			s_ptr = holder->content;
		}
	}
	return (0); // Str not found but not EOF;
}

static t_db	*file_search_aux(t_itree *T, int id, char *n_ptr)
{
	int		n_result_check;
	int		h_iter;
	char	*h_ptr;
	char	*s_ptr;
	t_db	*h_db;

	h_iter = 0;	
	h_db = ibt_get_db_by_id(T, id);
	h_ptr = h_db->content;
	while (1)
	{
		if(!h_ptr[h_iter])
		{
			if(h_db->next_id == -1)
				return (NULL);
			h_iter = 0;
			h_db = ibt_get_db_by_id(T, h_db->next_id);
			h_ptr = h_db->content;
		}
		if (h_ptr[h_iter] == n_ptr[0])
		{
			s_ptr = &h_ptr[h_iter];
			n_result_check = check_needle(T, h_db->id, n_ptr, s_ptr);
			if (n_result_check == 1)
				return (h_db);
			if (n_result_check == EOF)
				return (NULL);
		}
		s_ptr = NULL;
		h_iter++;
	}
	return (h_db);
}

t_db	*file_search(t_itable **list, t_itree *T, char *filename, char *str)
{
	int			start_id;
	t_itable	*list_node;

	list_node = it_search(*list, filename);
    if(list_node) {
		start_id = list_node->id;
		return (file_search_aux(T, start_id, str));
    }
	return (NULL);
}