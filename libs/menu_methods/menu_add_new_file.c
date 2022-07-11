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

void	menu_add_new_file(t_itree  **tree, t_itable **file_list, int *t, int *MAX_BLOCK_BUFFER)
{
	int			fsize;
	char		op;
	char		*newfile_name, *newfile_content;
	t_filedata 	file;
	FILE *fp;

	op = '\0';
	fsize = 0;
	fp = NULL;
	newfile_name = NULL;
	newfile_content = NULL;
	printf("Deseja criar um arquivo novo? (s/n):\n");
	getchar();
	op = getchar();
	op = tolower(op);
	if(op == 's'){
		printf("Insira o nome do arquivo a ser criado:\n");
		getchar();
		get_single_line_stdin(&newfile_name);
		if(it_search(*file_list, newfile_name)){
        	printf(">Já existe um arquivo de mesmo nome na árvore\n");
			return;
    	}
		printf("Insira o conteúdo do arquivo: (; para finalizar)\n");
		get_multi_lines_stdin(&newfile_content);
	}
	else if(op == 'n') {
		printf("Insira o nome do arquivo a ser carregado:\n");
		getchar();
		get_single_line_stdin(&newfile_name);
		if(it_search(*file_list, newfile_name)){
        	printf(">Já existe um arquivo de mesmo nome na árvore\n");
			return;
    	}
		fp = fopen(newfile_name, "r");
		if(!fp)
		{
			printf(">Arquivo não encontrado.\n");
			free(newfile_name);
			return;
		}
		fseek(fp, 0, SEEK_END);
		fsize = ftell(fp);
		rewind(fp);
		newfile_content = (char *) malloc(sizeof(char)*(fsize + 1));
		fread(newfile_content, fsize, 1, fp);
		fclose(fp);
		newfile_content[fsize] = 0;
	}
	file.filename = newfile_name;
	file.content = newfile_content;
	*tree = file_insert(file_list, *tree, *t, file, *MAX_BLOCK_BUFFER);	
	printf(">%s adicionado.\n", newfile_name);
	free(newfile_name);
	free(newfile_content);
}