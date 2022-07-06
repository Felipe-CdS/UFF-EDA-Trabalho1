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

t_itree *file_insert(t_itable **list, t_itree *T, int t, t_filedata data, int max_len)
{
    int i, id, txt_len;

    t_db *db;
    char *p;

    i = 0;
	p = NULL;
    db = NULL;
    id = db_getid(); 
	it_add_back(list, it_new(id, data.filename));
    txt_len = strlen(data.content);
	if(!txt_len)
	{
		db = db_new(id, -1, "");
		T = ibt_insert(T, db, t);
		return (T);
	}
    for(i = 0; i < txt_len; i = i + max_len){
		if(i)
			id = db_getid();
		p = strndup((data.content + i), max_len);
        db = db_new(id, -1, p);
        T = ibt_insert(T, db, t);
        free(p);
    }
    return T;
}