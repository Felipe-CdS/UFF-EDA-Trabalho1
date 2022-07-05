/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_tree_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:33:31 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/06/29 16:00:39 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inode_tree.h"

static t_itree	*split_node(t_itree *x, int i, t_itree *y, int t)
{
	int		j;
	t_itree	*z;

	z = ibt_new(t);
	z->n_db = t - 1;
	z->leaf = y->leaf;
	j = 0;
	while (j < (t - 1))
	{
		z->blocks[j] = y->blocks[(j + t)];
		j++;
	}
	if (!y->leaf)
	{
		j = 0;
		while (j < t)
		{
			z->c[j] = y->c[(j + t)];
			y->c[(j + t)] = NULL;
			j++;
		}
	}
	y->n_db = t - 1;
	j = x->n_db;
	while (j >= i)
	{
		x->c[(j + 1)] = x->c[j];
		j--;
	}
	x->c[i] = z;
	j = x->n_db;
	while (j >= i)
	{
		x->blocks[j] = x->blocks[(j - 1)];
		j--;
	}
	x->blocks[(i - 1)] = y->blocks[(t - 1)];
	x->n_db++;
	return (x);
}

static t_itree	*insert_non_full(t_itree *T, t_db *datablock, int t)
{
	int	i;

	i = T->n_db - 1;
	if (T->leaf)
	{
		while ((i >= 0) && (datablock->id < (T->blocks[i])->id))
		{
			T->blocks[(i + 1)] = T->blocks[i];
			--i;
		}
		T->blocks[i + 1] = datablock;
		T->n_db++;
		return (T);
	}
	while ((i >= 0) && (datablock->id < (T->blocks[i])->id))
		i--;
	i++;
	if (T->c[i]->n_db == ((2 * t) - 1))
	{
		T = split_node(T, (i + 1), T->c[i], t);
		if (datablock->id > (T->blocks[i])->id)
			i++;
	}
	T->c[i] = insert_non_full(T->c[i], datablock, t);
	return (T);
}

t_itree	*ibt_insert(t_itree *T, t_db *datablock, int t)
{
	t_itree	*new_node;

	if (ibt_search(T, datablock->id))
		return (T);
	if (!T)
	{
		T = ibt_new(t);
		T->blocks[0] = datablock;
		T->n_db = 1;
		return (T);
	}
	// printf("%d\n", T->n_db /*(T->blocks[0])->id*/); 	
	if (T->n_db == ((2 * t) - 1))
	{
		new_node = ibt_new(t);
		new_node->n_db = 0;
		new_node->leaf = 0;
		new_node->c[0] = T;
		new_node = split_node(new_node, 1, T, t);
		new_node = insert_non_full(new_node, datablock, t);
		return (new_node);
	}
	T = insert_non_full(T, datablock, t);
	return (T);
}
