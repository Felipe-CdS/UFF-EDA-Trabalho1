/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:58:59 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 17:27:51 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_methods.h"

static void file_remove_aux(t_itree **tree, int id, int t){
    int i;
    t_itree *aux;
    t_db *db;

	i = 0;
    aux = ibt_search((*tree), id);	
	if(!aux)
		return ((*tree));
	while((i < aux->n_db) && (aux->blocks[i]->id != id)) 
		i++;
	db = aux->blocks[i];
	printf("%s\n", db->content);
	(*tree) = file_remove_aux(T, db->next_id, t);
	// (*tree) = ibt_remove(*T, db, t);
}

t_itree *file_remove(t_itable **list, t_itree *tree, int t, char *filename){
    int id;
	t_itable *list_node;

	list_node = it_search(*list, filename);
    if(list_node) {
		id = list_node->id;
		file_remove_aux(tree, id, t);
		it_remove(list, list_node);
		printf(">%s removido.\n", filename);
    }
	printf("Arquivo não encontrado\n");
	return ((*T));
}