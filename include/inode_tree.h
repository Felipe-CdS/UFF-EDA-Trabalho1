/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:01:58 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/18 21:03:01 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INODE_TREE_H
# define INODE_TREE_H
# include <stdlib.h>
# include <stdio.h>
# include "data_block.h"

typedef struct s_itree
{
	int				leaf;
	int				n_db;		// Current number of datablocks
	t_db			**blocks;
	struct s_itree	**c;		// Child pointers
}				t_itree;

t_itree	*ibt_new(int t);
t_itree	*ibt_clear(t_itree *target); // Free all tree
t_itree	*ibt_search(t_itree *T, int db_id);
t_db	*ibt_get_db_by_id(t_itree *T, int id);
t_itree	*ibt_insert(t_itree *T, t_db *datablock, int t);
t_itree	*ibt_remove(t_itree *T, t_db *datablock, int t);
t_itree *ibt_reorganize_content(t_itree *T, int db_id, int t, size_t max_len);
void	ibt_print(t_itree *T);
#endif
