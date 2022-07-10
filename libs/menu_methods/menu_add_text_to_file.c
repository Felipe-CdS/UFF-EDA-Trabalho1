/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_add_new_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:27:20 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 16:29:07 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_methods.h"
#include "misc_methods.h"

void	menu_add_text_to_file(t_itree  **tree, t_itable **file_list, int *t, int *MAX_BLOCK_BUFFER)
{
	int			pos;
	char		*filename, *content;
	t_filedata 	file;

    pos = 0;
	filename = NULL;
	content = NULL;

    printf("Insira o nome do arquivo a inserir novas informações:\n");
    getchar();
    get_single_line_stdin(&filename);
    printf("Insira o conteúdo a ser inserido: (; para finalizar)\n");
    get_multi_lines_stdin(&content);
    printf("Insira a posição dentro do arquivo:\n");
    scanf("%d", &pos);
	file.filename = filename;
	file.content = content;
	*tree = file_insert_text(file_list, *tree, *t, file, *MAX_BLOCK_BUFFER, pos);	
	printf(">String '%s' inserida em '%s' na posição %d.\n", content, filename, pos);
	free(filename);
	free(content);
}