/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_print_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:48:36 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 11:51:01 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_methods.h"
#include "misc_methods.h"

void	menu_print_file(t_itree **tree, t_itable **file_list)
{
	char		*filename;

    filename = NULL;

    printf("Insira o nome do arquivo a a ser impresso:\n");
    getchar();
    get_single_line_stdin(&filename);
    file_print(file_list, *tree, filename);
}