/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:34:57 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 19:51:11 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inode_table.h"
#include "inode_tree.h"
#include "menu_methods.h"

int	main(void)
{
	char		op;
	t_itree		*tree;
	t_itable	*file_list;
	int			T, MAX_BLOCK_BUFFER;

	menu_start_routine(&tree, &file_list, &T, &MAX_BLOCK_BUFFER, &op);
	while (op != 'e')
	{
		menu_get_next_op(&op);
		if (op == 'a')
			menu_add_new_file(&tree, &file_list, &T, &MAX_BLOCK_BUFFER);
		if (op == 'r')
			menu_remove_file(&tree, &file_list, &T);
		if (op == 's')
			menu_search_str(&tree, &file_list);
		if (op == 'l')
			menu_print_list(&file_list);
		if (op == 't')
			menu_print_tree(&tree);
		if (op == 's')
			menu_search_str(&tree, &file_list);
		if (op == 'i')
			menu_add_text(&tree, &file_list, &T, &MAX_BLOCK_BUFFER);
		if (op == 'p')
			menu_print_file(&tree, &file_list);
	}
	menu_free_routine(&tree, &file_list);
	return (0);
}
