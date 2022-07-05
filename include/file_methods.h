/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_methods.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 08:59:48 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/05 09:03:02 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_METHODS
# define FILE_METHODS
#include "inode_tree.h"
#include <string.h>

t_itree *file_insert(t_itree *T, int t, char *txt, int max_len);

#endif