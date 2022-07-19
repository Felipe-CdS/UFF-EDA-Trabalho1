/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:58:59 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/06 12:56:20 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_methods.h"

void file_print_aux(t_itree *T, int id){
    int i = 0;
    t_itree *aux;
    t_db *db;

    aux = ibt_search(T, id);
    if(aux){
        while((i < aux->n_db) && (aux->blocks[i]->id != id)) i++;
        db = aux->blocks[i];

        // printf("\nBLOCO %d(ant: %d | prox: %d)\n", db->id, db->previous_id, db->next_id);
        printf("%s", db->content);
        file_print_aux(T, db->next_id);
    }
}

void file_print(t_itable **list, t_itree *T, char *filename){
    int id;
	t_itable *list_node;

	list_node = it_search(*list, filename);
    if(list_node) {
		id = list_node->id;
        printf("Arquivo [%s]:\n", filename);
		file_print_aux(T, id);
		printf("\n\n");
    }
    else printf("Arquivo não encontrado\n");
}