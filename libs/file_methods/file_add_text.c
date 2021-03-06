/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_add_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:58:59 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 19:54:34 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_methods.h"

t_itree *file_add_text(t_itable **list, t_itree *T, int t, t_filedata data, int max_len, int pos)
{
    int id, i, j, new_id, previous_id, next_id, current_pos = 0, txt_len;
    t_db *db, *db_m, *db_n, *db_o;
	t_itable *list_node;
    char *p, *split_node_text;

    txt_len = strlen(data.content);
    if(!txt_len) return (T);
	list_node = it_search(*list, data.filename);
    if(list_node) {
		id = list_node->id;
        if(pos < -1) pos = 0;
        do{
            j = 0;
            
            db = ibt_get_db_by_id(T, id);
            if(!db){
                printf("Posição não encontrada.\n");
                return T;
            }
            while(db->content[j] && current_pos != pos) {
                current_pos++;
                j++;
            }
            id = db->next_id;
        } while((current_pos != pos) && (id != -1));
        new_id = db_getid();
        if(j == 0){
            if(current_pos == 0) list_node->id = new_id;
            next_id = db->id;
            previous_id = db->previous_id;
            db->previous_id = new_id;
        }
        else if((pos == -1) || (j == ((int) strlen(db->content)) && id == -1)){
            pos = -1;
            next_id = -1;
            previous_id = db->id;
            db->next_id = new_id;
        }
        else {
            split_node_text = strndup((db->content + j), max_len);
            db_n = db_new(new_id, db->id, split_node_text);
            db_n->next_id = db->next_id;
            db->content[j] = 0;
            db->next_id = new_id;
            T = ibt_insert(T, db_n, t);
            new_id = db_getid();
            next_id = db->next_id;
            previous_id = db->id;
            db->next_id = new_id;
        }
        for(i = 0; i < txt_len; i = i + max_len){
            if(i) new_id = db_getid();
            p = strndup((data.content + i), max_len);
            db_m = db_new(new_id, previous_id, p);
            db_m->next_id = new_id + 1;
            if(i + max_len >= txt_len) db_m->next_id = next_id;
            previous_id = new_id;
            T = ibt_insert(T, db_m, t);
            free(p);
        }
        if((j != 0) && (pos != -1)) {
            db_n->previous_id = previous_id;
            db_o = ibt_get_db_by_id(T, db_n->next_id);
            db_o->previous_id = db_n->id;
        }
        return T;
    }
    else printf("Arquivo não encontrado.\n");
	return(T);
}