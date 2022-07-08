/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_tree_remove_case2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:30:48 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/08 16:10:06 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inode_tree.h"
#include "private_headers/inode_tree_rmv_cases.h"

static t_itree *case_2a(t_itree *T, int t, int i)
{
	t_db	*tmp;
	t_itree	*y;

	y = T->c[i];
	while (!y->leaf)
		y = y->c[y->n_db];
	tmp = y->blocks[(y->n_db - 1)];
	T->c[i] = ibt_remove(T->c[i], tmp, t);
	T->blocks[i] = tmp;
	return (T);
}

static t_itree *case_2b(t_itree *T, int t, int i)
{
	t_db	*tmp;
	t_itree	*y;

	y = T->c[(i + 1)];
	while (!y->leaf)
		y = y->c[0];
	tmp = y->blocks[0];
	y = ibt_remove(T->c[(i + 1)], tmp, t);
	T->blocks[i] = tmp;
	return (T);
}

static t_itree *case_2c(t_itree *T, t_db *datablock, int t, int i)
{
	int		j;
	t_itree	*tmp;
	t_itree	*y;
	t_itree	*z;

	y = T->c[i];
	z = T->c[(i + 1)];
	y->blocks[y->n_db] = datablock;
	j = 0;
	while (j < (t - 1))
	{
		y->blocks[(t + j)] = z->blocks[j];
		j++;
	}
	j = 0;
	while (j <= t)
	{
		y->c[(t + j)] = z->c[j];
		z->c[j] = NULL;
		j++;
	}
	y->n_db = (2 * t) - 1;
	j = i;
	while (j < (T->n_db - 1))
	{
		T->blocks[j] = T->blocks[(j + 1)];
		j++;
	}
	j = (i + 1);
	while (j < T->n_db)
	{
		T->c[j] = T->c[(j + 1)];
		j++;
	}
	T->c[j] = NULL;
	T->n_db--;
	if (!T->n_db)
	{
		tmp = T;
		T = T->c[0];
		tmp->c[0] = NULL;
		ibt_clear(tmp);
		T = ibt_remove(T, datablock, t);
	}
	else
		T->c[i] = ibt_remove(T->c[i], datablock, t);
	return (T);
}

t_itree	*rmv_case2_handler(t_itree *T, t_db *datablock, int t, int i)
{
	if (!T->leaf && CHK_THIS_C_T)
		T = case_2a(T, t, i);
	if (!T->leaf && CHK_NEXT_C_T)
		T = case_2b(T, t, i);
	if (!T->leaf && CHK_NEXT_C_MIN && CHK_THIS_C_MIN)
		T = case_2c(T, datablock, t, i);
	return (T);
}
