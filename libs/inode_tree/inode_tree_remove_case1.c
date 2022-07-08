/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_tree_remove_case1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:36:34 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/08 12:55:11 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inode_tree.h"
#include "private_headers/inode_tree_rmv_cases.h"

t_itree	*rmv_case1_handler(t_itree *T, int i)
{
	while (i < (T->n_db - 1))
	{
		T->blocks[i] = T->blocks[(i + 1)];
		i++;
	}
	T->n_db--;
	if (!T->n_db)
	{
		ibt_clear(T);
		T = NULL;
	}
	return (T);
}
