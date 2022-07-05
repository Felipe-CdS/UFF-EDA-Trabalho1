/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:58:59 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/05 09:03:15 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_methods.h"

t_itree *file_insert(t_itree *T, int t, char *txt, int max_len)
{
    int i, id, txt_len;

    t_db *db;
    char *p;

    i = 0;
    id = 0;
    txt_len = strlen(txt);
    for(i = 0; i < txt_len; i = i + max_len){
        p = (char *) malloc( sizeof(char) * (max_len + 1));
        p = strncpy(p, (txt + i), max_len);
        p[max_len] = 0;
        db = db_new(id, -1, &p);
        T = ibt_insert(T, db, t);
        id++;
        free(p);
    }
    return T;
}