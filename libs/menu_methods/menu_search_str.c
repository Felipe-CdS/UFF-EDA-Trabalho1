/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_search_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:56:21 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 16:43:01 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_methods.h"
#include "misc_methods.h"

void	menu_search_str(t_itree  **tree, t_itable **file_list)
{
	t_db	*result;
	char	*filename;
	char	*search_str;

	result = NULL;
	filename = NULL;
	search_str = NULL;
	if(!(*tree))
	{
		printf(">A arvore esta vazia no momento. Adicione um arquivo para utilizar essa opção.\n");
		return;
	}
	printf("Insira o nome do arquivo onde ocorre a busca:\n");
	getchar();
	get_single_line_stdin(&filename);
	printf("Insira a string da busca:\n");
	get_single_line_stdin(&search_str);
	result = file_search(file_list, *tree, filename, search_str);
	if(!result)
		printf(">Arquivo ou string não encontrado.\n");
	else
		printf(">Primeira ocorrencia de \"%s\" começa no bloco {ID: %02d; Conteudo: |%s|}\n\n", search_str, result->id, result->content);
	free(filename);
	free(search_str);
}