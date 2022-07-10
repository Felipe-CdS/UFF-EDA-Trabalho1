/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_remove_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 11:46:41 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 11:54:59 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_methods.h"

void	menu_remove_file(t_itree  **tree, t_itable **file_list, int *t)
{
	char *filename;
	
	filename = NULL;
	printf("Insira o nome do arquivo a ser removido:\n");
	scanf("%*c%[^\n]", filename);
	*tree = file_remove(file_list, *tree, *t, filename);
}