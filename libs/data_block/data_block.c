/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_block.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:10:11 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/06 12:51:53 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_block.h"
#include <string.h>

static int id = 1;

t_db	*db_new(int id, int previous_id, char *content)
{
	t_db	*new_block;
	new_block = (t_db *) malloc(sizeof(t_db));

	if (!new_block)
		return (new_block);
	new_block->id = id;
	new_block->previous_id = previous_id;
	new_block->next_id = -1;
	new_block->content = strdup(content);
	return (new_block);
}

void	db_del(t_db *target)
{
	free(target->content);
	free(target);
}

int		db_getid()
{
	return (id++);
}
