/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_tree_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:34:29 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/04 14:17:22 by fcoutinh         ###   ########.fr       */
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

	// no total tem 3 stacks: 
		// chamada pela minha função
		// pelo caso 3b2
		// pela chamada recursiva da stack do caso 3b2
	// if(datablock->id == 8) printf("stack\n");
	// if(datablock->id == 8) ibt_print(T);

	if (rmv_case1_handler(T, datablock, i))
		return (T);
	if (rmv_case2_handler(T, datablock, t, i))
		return (T);
	if (rmv_case3_handler(T, datablock, t, i)){
		return (T);
	}
	T->c[i] = ibt_remove(T->c[i], datablock, t);

	// em alguma stack (não sei se é a primeira) a arvore do 8 é retornada do jeito certo
	// if(datablock->id == 8) ibt_print(T);
	// printf("\n");

	return (T);
}
