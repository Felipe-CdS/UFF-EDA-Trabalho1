/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:58:59 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/08 14:16:29 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_methods.h"

t_itree *file_remove_aux(t_itree *T, int id, int t){
    int i = 0;
    t_itree *aux;
    t_db *db;

    aux = ibt_search(T, id);
    while((i < aux->n_db) && (aux->blocks[i]->id != id)) 
		i++;
    db = aux->blocks[i];
    if(db->next_id != -1)
		T = file_remove_aux(T, db->next_id, t);
    return (ibt_remove(T, db, t));
}

t_itree *file_remove(t_itable **list, t_itree *T, int t, char *filename){
    int id;
	t_itable *list_node;

	list_node = it_search(*list, filename);
    if(list_node) {
		id = list_node->id;
		T = file_remove_aux(T, id, t);
		it_remove(list, list_node);
		printf(">%s removido.\n", filename);
		return (T);
    }
	printf("Arquivo não encontrado\n");
	return (NULL);  
}