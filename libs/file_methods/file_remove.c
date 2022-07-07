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

t_itree *file_remove_aux(t_itree *T, int id, int t){
    int i = 0;
    t_itree *aux;
    t_db *db;

    aux = ibt_search(T, id);
    while((i < aux->n_db) && (aux->blocks[i]->id != id)) i++;
    db = aux->blocks[i];
    
    if(db->next_id != -1) T = file_remove_aux(T, db->next_id, t);

    printf("REMOVENDO %d\n", id);
    ibt_print(T);
    printf("\n");

    // comparação entre o retorno do 8 e 9 (descomentar só 1 por vez)
    // printf("TESTANDO RETORNO DO %d\n", id);
    // if(db->id == 9) ibt_print(ibt_remove(T, db, t));
    // if(db->id == 8) ibt_print(ibt_remove(T, db, t));

    return ibt_remove(T, db, t);
}

t_itree *file_remove(t_itable **list, t_itree *T, int t, char *filename){
    int id;
    id = it_search(*list, filename);
    if(!id) {
        printf("Arquivo não encontrado\n");
        return NULL;
    }
    T = file_remove_aux(T, id, t);
    return (T);
}