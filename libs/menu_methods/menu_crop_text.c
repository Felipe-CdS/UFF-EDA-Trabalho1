/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_crop_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:53:00 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 22:39:49 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_methods.h"
#include "misc_methods.h"

void	menu_crop_text(t_itree  **tree, t_itable **file_list, int *t, int *MAX_BLOCK_BUFFER)
{
	t_itree *result;
	t_itable *list_node;
	char	*filename;
	char	*search_str;

	result = NULL;
	filename = NULL;
	search_str = NULL;
	list_node = NULL;
	if(!(*tree))
	{
		printf(">A arvore esta vazia no momento. Adicione um arquivo para utilizar essa opção.\n");
		return;
	}
	printf("Insira o nome do arquivo que deseja cortar:\n");
	getchar();
	get_single_line_stdin(&filename);
	printf("Insira a string que deve ser removida:\n");
	get_single_line_stdin(&search_str);	
	list_node = it_search(*file_list, filename);
	if(list_node) 
	{
		result = file_crop_text(file_list, *tree, *t, filename, search_str, *MAX_BLOCK_BUFFER);
		(*tree) = result;
		printf(">Arquivo cortado com sucesso.\n");
	}
	else
	{
		printf(">Arquivo não encontrado.\n");
	}
	free(filename);
	free(search_str);
}