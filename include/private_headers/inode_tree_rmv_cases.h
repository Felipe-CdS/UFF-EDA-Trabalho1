/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_tree_rmv_cases.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:47:57 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/08 11:28:09 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INODE_TREE_RMV_DEFS
# define INODE_TREE_RMV_DEFS

#define CHK_PREV_C_T	(T->c[(i - 1)])->n_db >= t
#define CHK_THIS_C_T	(T->c[(i + 0)])->n_db >= t
#define CHK_NEXT_C_T	(T->c[(i + 1)])->n_db >= t
#define CHK_PREV_C_MIN	(T->c[(i - 1)])->n_db == (t - 1)
#define CHK_THIS_C_MIN	(T->c[(i + 0)])->n_db == (t - 1)
#define CHK_NEXT_C_MIN	(T->c[(i + 1)])->n_db == (t - 1)

t_itree	*rmv_case1_handler(t_itree *T, int i);
t_itree	*rmv_case2_handler(t_itree *T, t_db *datablock, int t, int i);
t_itree	*rmv_case3_handler(t_itree *T, t_db *datablock, int t, int i);
#endif