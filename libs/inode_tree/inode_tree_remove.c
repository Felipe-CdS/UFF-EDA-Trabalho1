/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_tree_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:34:29 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 19:29:45 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inode_tree.h"
#include "private_headers/inode_tree_rmv_cases.h"

t_itree	*ibt_remove(t_itree *T, t_db *datablock, int t)
{
	int	i;
	
	i = 0;
	if (!T)
		return (T);	
	while (i < T->n_db && (T->blocks[i])->id < datablock->id)
		i++;
	if (i < T->n_db && (T->blocks[i])->id == datablock->id && (T->leaf))
	{
		return (rmv_case1_handler(T, i));
	}		
	if (i < T->n_db && (T->blocks[i])->id == datablock->id)
	{
		return (rmv_case2_handler(T, datablock, t, i));
	}		
	if ((T->c[i])->n_db == (t - 1))
	{
		return (rmv_case3_handler(T, datablock, t, i));
	}		
	T->c[i] = ibt_remove(T->c[i], datablock, t);
	return (T);
}

