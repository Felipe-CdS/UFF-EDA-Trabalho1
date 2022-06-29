/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_tree.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:01:58 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/06/29 11:15:55 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INODE_TREE_H
# define INODE_TREE_H
# include <stdlib.h>

typedef struct s_datablock
{
	int		id;
	int		previous_id;
	int		next_id;
	char	*content;
}				t_db;

typedef struct s_itree
{
	int				leaf;
	int				n_db;		// Current number of datablocks
	t_db			*blocks;
	struct s_itree	**c;		// Child pointers
}				t_itree;
#endif
