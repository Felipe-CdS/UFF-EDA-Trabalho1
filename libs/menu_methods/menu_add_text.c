/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_add_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:37:14 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 19:50:05 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_methods.h"
#include "misc_methods.h"

void	menu_add_text(t_itree  **tree, t_itable **file_list, int *t, int *MAX_BLOCK_BUFFER)
{
	int		pos;
	char	*filename;
	char	*content;
	t_filedata 	file;

	filename = NULL;
	content = NULL;
	printf("Insira o nome do arquivo:\n");
	getchar();
	get_single_line_stdin(&filename);
	printf("Insira a posição (final do arquivo: -1):\n");
	scanf("%d", &pos);
	printf("Insira o conteúdo a ser adicionado:\n");
	get_single_line_stdin(&content);
	file.filename = filename;
	file.content = content;
	(*tree) = file_add_text(file_list, (*tree), *t, file, *MAX_BLOCK_BUFFER, pos);
	free(filename);
	free(content);
}
