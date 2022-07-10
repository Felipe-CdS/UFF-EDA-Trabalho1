/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:58:59 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 18:14:07 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_methods.h"

t_itree *file_remove(t_itable **list, t_itree *tree, int t, char *filename){
	int i;
	int id;
	t_db *db;
	t_itree *aux;
	t_itable *list_node;
	
	list_node = it_search(*list, filename);
    if(list_node) {
		id = list_node->id;
		while(id != -1)
		{
			i = 0;
			aux = ibt_search(tree, id);	
			while((aux) && (i < aux->n_db) && (aux->blocks[i]->id != id))
				i++;
			db = aux->blocks[i];
			id = db->next_id;
			tree = ibt_remove(tree, db, t);
		}
		it_remove(list, list_node);
		printf(">%s removido.\n", filename);
		return (tree);
	}
	printf("Arquivo não encontrado\n");
	return (tree);
}