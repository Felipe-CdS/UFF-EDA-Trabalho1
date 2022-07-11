/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_methods.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:59:48 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 16:21:57 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_METHODS_H
# define FILE_METHODS_H
#include "inode_tree.h"
#include "inode_table.h"
#include <string.h>

typedef struct s_filedata
{
	char	*filename;
	char	*content;
}				t_filedata;

t_itree *file_insert(t_itable **list, t_itree *T, int t, t_filedata data, int max_len);
t_itree *file_remove(t_itable **list, t_itree *T, int t, char *filename);
t_itree	*file_add_text(t_itable **list, t_itree *T, int t, t_filedata data, int max_len, int pos);
t_db	*file_search(t_itable **list, t_itree *T, char *filename, char *str);

void 	file_save(t_itable **list, t_itree *T, char *filename);
void 	file_print(t_itable **list, t_itree *T, char *filename);
#endif