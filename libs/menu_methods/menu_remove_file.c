/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_remove_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:46:41 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 17:25:47 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_methods.h"
#include "misc_methods.h"

void	menu_remove_file(t_itree  **tree, t_itable **file_list, int *t)
{
	char *filename;
	
	filename = NULL;
	printf("Insira o nome do arquivo a ser removido:\n");
	getchar();
	get_single_line_stdin(&filename);
	*tree = file_remove(file_list, *tree, *t, filename);
}