/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_methods.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:59:48 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/06 12:34:13 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_METHODS
# define FILE_METHODS
#include "inode_tree.h"
#include "inode_table.h"
#include <string.h>

typedef struct s_filedata
{
	char	*filename;
	char	*content;
}				t_filedata;


t_itree *file_insert(t_itable **list, t_itree *T, int t, t_filedata data, int max_len);

#endif