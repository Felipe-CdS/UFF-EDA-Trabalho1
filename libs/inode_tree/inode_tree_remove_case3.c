/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_tree_remove_case3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:18:01 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/04 20:30:44 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inode_tree.h"
#include "private_headers/inode_tree_rmv_cases.h"

static void	case_3a_1(t_itree *T, t_db *datablock, int t, int i)
{
	int		j;
	t_itree	*y;
	t_itree	*z;

	y = T->c[i];
	z = T->c[(i + 1)];
	y->blocks[(t - 1)] = T->blocks[i];
	y->n_db++;
	T->blocks[i] = z->blocks[0];
	j = 0;
	while (j < (z->n_db - 1))
	{
		z->blocks[j] = z->blocks[(j + 1)];
		j++;
	}
	y->c[y->n_db] = z->c[0];
	j = 0;
	while (j < z->n_db)
	{
		z->c[j] = z->c[(j + 1)];
		j++;
	}
	z->n_db--;
	T->c[i] = ibt_remove(T->c[i], datablock, t);
}

static void	case_3a_2(t_itree *T, t_db *datablock, int t, int i)
{
	int		j;
	t_itree	*y;
	t_itree	*z;

	y = T->c[i];
	z = T->c[(i - 1)];
	j = y->n_db;
	while (j > 0)
	{
		y->blocks[j] = y->blocks[(j - 1)];
		j--;
	}
	j = y->n_db + 1;
	while (j > 0)
	{
		y->c[j] = y->c[(j - 1)];
		j--;
	}
	y->blocks[0] = T->blocks[(i - 1)];
	y->n_db++;
	T->blocks[(i - 1)] = z->blocks[(z->n_db - 1)];
	y->c[0] = z->c[z->n_db];
	z->n_db--;
	T->c[i] = ibt_remove(y, datablock, t);
}

static void	case_3b_1(t_itree *T, t_db *datablock, int t, int i)
{
	int		j;
	t_itree	*tmp;
	t_itree	*y;
	t_itree	*z;

	y = T->c[i];
	z = T->c[(i + 1)];
	y->blocks[(t - 1)] = T->blocks[i];
	y->n_db++;
	j = 0;
	while (j < (t - 1))
	{
		y->blocks[(t + j)] = z->blocks[j];
		y->n_db++;
		j++;
	}
	if (!y->leaf)
	{
		j = 0;
		while (j < t)
		{
			y->c[(t + j)] = z->c[j];
			z->c[j] = NULL;
			j++;
		}
		ibt_clear(z);
	}
	j = i;
	while (j < (T->n_db - 1))
	{
		T->blocks[j] = T->blocks[(j + 1)];
		T->c[(j + 1)] = T->c[(j + 2)];
		j++;
	}
	T->c[T->n_db] = NULL;
	T->n_db--;
	if (!T->n_db)
	{
		tmp = T;
		T = T->c[0];
		tmp->c[0] = NULL;
		ibt_clear(tmp);
	}
	T = ibt_remove(T, datablock, t);
}

static void	case_3b_2(t_itree *T, t_db *datablock, int t, int i)
{
	int		j;
	t_itree	*tmp;
	t_itree	*y;
	t_itree	*z;

	y = T->c[i];
	z = T->c[(i - 1)];
	if (i == T->n_db)
		z->blocks[(t - 1)] = T->blocks[(i - 1)];
	else
		z->blocks[(t - 1)] = T->blocks[i];
	z->n_db++;
	j = 0;
	while (j < (t - 1))
	{
		z->blocks[(t + j)] = y->blocks[j];
		z->n_db++;
		j++;
	}
	if (!z->leaf)
	{
		j = 0;
		while (j < t)
		{
			z->c[(t + j)] = y->c[j];
			y->c[j] = NULL;
		}
		ibt_clear(y);
	}
	T->c[T->n_db] = NULL;
	T->n_db--;
	if (!T->n_db)
	{
		tmp = T;
		T = T->c[0];
		tmp->c[0] = NULL;
		ibt_clear(tmp);
	}
	else
	T->c[(i - 1)] = z;
	T = ibt_remove(T, datablock, t);
}

int	rmv_case3_handler(t_itree *T, t_db *datablock, int t, int i)
{
	t_itree	*y;
	t_itree	*z;

	y = T->c[i];
	z = NULL;
	if (y->n_db == (t - 1))
	{
		if ((i < T->n_db) && CHK_NEXT_C_T)
		{
			case_3a_1(T, datablock, t, i);
			return (1);
		}
		if ((!z) && (i > 0) && CHK_PREV_C_T)
		{
			case_3a_2(T, datablock, t, i);
			return (1);
		}
		if ((!z) && i < T->n_db && CHK_NEXT_C_MIN)
		{
			case_3b_1(T, datablock, t, i);
			return (1);
		}
		if ((!z) && (i > 0) && CHK_PREV_C_MIN)
		{
			case_3b_2(T, datablock, t, i);
			return (1);
		}
	}
	return (0);
}
