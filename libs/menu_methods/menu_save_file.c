/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_print_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:51:30 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 19:53:27 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_methods.h"
#include "misc_methods.h"

void	menu_save_file(t_itree  **tree, t_itable **file_list)
{
	char	*filename;

	filename = NULL;
	printf("Insira o nome do arquivo a ser salvo:\n");
	getchar();
	get_single_line_stdin(&filename);
	file_save(file_list, (*tree), filename);
	free(filename);
}