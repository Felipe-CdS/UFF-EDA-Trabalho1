/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:20:21 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 20:23:03 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_methods.h"
#include "misc_methods.h"

static t_db	*file_search_aux(t_itree *T, int id, char *str)
{
	int 	this_id, next_id;
	t_db	*this_id_db, *next_id_db, *result;
	char 	*this_id_content, *next_id_content;
	char	*content;

	this_id = id;
	content = NULL;
	this_id_content = NULL;
	next_id_content = NULL;	
	while(this_id != -1)
	{
		this_id_content = NULL;
		next_id_content = NULL;	
		this_id_db = ibt_get_db_by_id(T, this_id);
		next_id = this_id_db->next_id;
		next_id_db = ibt_get_db_by_id(T, next_id);

		this_id_content = strdup(this_id_db->content);
		if(next_id != -1)
			next_id_content = strdup(next_id_db->content);

		content = ft_strjoin(this_id_content, next_id_content);
		
		if(ft_strnstr(content, str, strlen(content)))
		{
			result = this_id_db;
			if(ft_strnstr(next_id_content, str, strlen(content)))
				result = next_id_db;
			break;
		}			
		this_id = next_id;
	}
	free(content);
	free(this_id_content);
	free(next_id_content);
	if(this_id != -1)
		return (result);
	return(NULL);
}

t_db	*file_search(t_itable **list, t_itree *T, char *filename, char *str)
{
	int		start_id;
	t_itable	*list_node;

	list_node = it_search(*list, filename);
    if(list_node) {
		start_id = list_node->id;
		return (file_search_aux(T, start_id, str));
    }
	return (NULL);  
}