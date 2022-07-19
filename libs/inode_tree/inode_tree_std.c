/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_tree_std.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:49:10 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/18 21:57:19 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inode_tree.h"
#include "misc_methods.h"

t_itree	*ibt_new(int t)
{
	int		i;
	t_itree	*new_node;

	new_node = (t_itree *) malloc(sizeof(t_itree));
	if (!new_node)
		return (NULL);
	new_node->leaf = 1;
	new_node->n_db = 0;
	new_node->blocks = (t_db **) malloc(sizeof(t_db *) * ((t * 2) - 1));
	new_node->c = (t_itree **) malloc(sizeof(t_itree *) * t * 2);
	i = 0;
	while (i < (t * 2))
	{
		new_node->c[i] = NULL;
		i++;
	}
	i = 0;
	return (new_node);
}

t_itree	*ibt_clear(t_itree *target)
{
	int	i;

	if (target)
	{
		if (!target->leaf)
		{
			i = 0;
			while (i < target->n_db)
			{
				ibt_clear(target->c[i]);
				i++;
			}
		}
		free(target->blocks); // mem leak: implement function to free each block
		free(target->c);
		free(target);
	}
	return (NULL);
}

t_itree	*ibt_search(t_itree *T, int db_id)
{
	int	i;

	i = 0;
	if (!T || db_id == -1)
		return (NULL);
	while (i < T->n_db && db_id > (T->blocks[i])->id)
		i++;
	if (i < T->n_db && db_id == (T->blocks[i])->id)
		return (T);
	if (T->leaf)
		return (NULL);
	return (ibt_search(T->c[i], db_id));
}

static void	print_aux(t_itree *T, int level)
{
	t_db *holder;
	int	i;
	int	j;
	level++;

	if (T)
	{
		i = 0;
		while (i <= (T->n_db - 1))
		{
			print_aux(T->c[i], (level + 1));
			j = 0;
			while (j <= level)
			{
				printf("\t");
				j++;
			}
			holder = T->blocks[i];
			printf("%02d |", holder->id);
			print_ascii_content(holder->content);
			printf("|\n");
			i++;
		}
		print_aux(T->c[i], (level + 1));
	}
}

void	ibt_print(t_itree *T)
{
	if(!T)
		printf(">A arvore esta vazia no momento. Adicione um arquivo para utilizar essa opção.\n\n");
	else
		print_aux(T, 0);
}

t_db	*ibt_get_db_by_id(t_itree *T, int id)
{
	int		i;
    t_itree	*aux;
    t_db	*db;

	i = 0;
	aux = ibt_search(T, id);
	if(!aux)
		return (NULL);
	while((i < aux->n_db) && (aux->blocks[i]->id != id)) 
		i++;
	db = aux->blocks[i];
	return (db);
}

t_itree *ibt_reorganize_content(t_itree *T, int db_id, int t, size_t max_len)
{
	size_t	crop_size;
	t_db	*holder, *next;

	holder = ibt_get_db_by_id(T, db_id);
	if(holder->next_id == -1)
		return (T);
	next = ibt_get_db_by_id(T, holder->next_id);
	crop_size = (max_len - strlen(holder->content));
	ft_strlcat(holder->content, next->content, (max_len + 1));
	if(strlen(next->content) < crop_size)
	{
		if(ibt_get_db_by_id(T, next->next_id))
			ibt_get_db_by_id(T, next->next_id)->previous_id = holder->id;
		holder->next_id = next->next_id;

		T = ibt_remove(T, next, t);
	}
	else
	{
		memmove(next->content, (next->content + crop_size), max_len);
	}		
	if(strlen(holder->content) < max_len)
		T = ibt_reorganize_content(T, holder->id, t, max_len);
	else
		T = ibt_reorganize_content(T, holder->next_id, t, max_len);
	return (T);
}
