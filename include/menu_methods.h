/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_methods.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:12:26 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 22:38:25 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_METHODS_H
# define MENU_METHODS_H
#include "inode_tree.h"
#include "file_methods.h"
#include "inode_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void	menu_start_routine(t_itree  **tree, t_itable **file_list, int *t, int *MAX_BLOCK_BUFFER, char *op);
void    menu_add_text_to_file(t_itree  **tree, t_itable **file_list, int *t, int *MAX_BLOCK_BUFFER);
void	menu_add_new_file(t_itree  **tree, t_itable **file_list, int *t, int *MAX_BLOCK_BUFFER);
void	menu_add_text(t_itree  **tree, t_itable **file_list, int *t, int *MAX_BLOCK_BUFFER);
void	menu_remove_file(t_itree  **tree, t_itable **file_list, int *t);
void	menu_free_routine(t_itree  **tree, t_itable **file_list);
void	menu_crop_text(t_itree  **tree, t_itable **file_list, int *t, int *MAX_BLOCK_BUFFER);
void	menu_search_str(t_itree  **tree, t_itable **file_list);
void	menu_print_file(t_itree  **tree, t_itable **file_list);
void	menu_save_file(t_itree  **tree, t_itable **file_list);
void	menu_print_list(t_itable **file_list);
void	menu_print_tree(t_itree  **tree);
void	menu_get_next_op(char *op);
#endif