/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_tree_std.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:49:10 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 18:37:12 by fcoutinh         ###   ########.fr       */
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
			for(i = 0; i < target->n_db; i++)
				ibt_clear(target->c[i]);
		}
		for(i = 0; i < target->n_db; i++) 
			db_del(target->blocks[i]);
		free(target->blocks);
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
