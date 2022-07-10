/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:34:57 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/08 14:12:10 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inode_table.h"
#include "inode_tree.h"
#include "file_methods.h"
#include <string.h>
#include <ctype.h>

static void test_insert_file()
{
	int			i, t, pos, max_buffer, fsize;
	t_itable	*file_list;
	t_itree		*tree;
	char 		*filename, *content, *newfile_name, *newfile_content, op;
	t_filedata 	file;
	FILE *fp;
	
	t = 2;
	max_buffer = 20;
	file_list = NULL;
	tree = NULL;

	filename = (char *) malloc(sizeof(char)*1000);
	content = (char *) malloc(sizeof(char)*1000);
	newfile_name = (char *) malloc(sizeof(char)*1000);
	newfile_content = (char *) malloc(sizeof(char)*1000);

	// file3.filename = "X.pdf";
	// file3.content = ""; // handle NULL content or filename

	// file4.filename = "invisible.bin";
	// file4.content = "\t\v\f\r\n \f-06050\1\2"; // handle non printable chars and fix '\n'

	i = 0;

	printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
	scanf("%d", &t);

	if(t < 2) t = 2;
	while(i != -1){
		printf("Escolha uma operação:\n\na: adicionar arquivo;\nr: remover arquivo;\nl: printar tabela;\nt: printar arvore;\np: printar arquivo\ni: inserir nova informação em um arquivo\n");
		scanf(" %c", &op);
		printf("\n");
		op = tolower(op);
		if(op == 'a'){
			printf("Deseja criar um arquivo novo? (s/n):\n");
			scanf(" %c", &op);
			printf("\n");
			op = tolower(op);
			if(op == 's'){
				printf("Insira o nome do arquivo a ser criado:\n");
				scanf("%*c%[^\n]", newfile_name);
				printf("\n");
				printf("Insira o conteúdo do arquivo:\n");
				scanf("%*c%[^\n]", newfile_content);
				printf("\n");

				file.filename = strdup(newfile_name);
				file.content = strdup(newfile_content);

				tree = file_insert(&file_list, tree, t, file, max_buffer);
			}
			else if(op == 'n') {
				printf("Insira o nome do arquivo a ser carregado:\n");
				scanf("%*c%[^\n]", filename);	
				fp = fopen(filename, "r");
				if(!fp) 
					printf("Arquivo não encontrado\n");
				else {
					fseek(fp, 0, SEEK_END);
					fsize = ftell(fp);
					rewind(fp);
					content = (char *) malloc(sizeof(char)*(fsize + 1));
					fread(content, fsize, 1, fp);
					fclose(fp);
					content[fsize] = 0;

					file.filename = strdup(filename);
					file.content = strdup(content);

					tree = file_insert(&file_list, tree, t, file, max_buffer);
				}
			}
		}
		else if (op == 'r'){
			printf("Insira o nome do arquivo a ser removido:\n");
			scanf("%*c%[^\n]", filename);
			tree = file_remove(&file_list, tree, t, filename);
		}
		else if (op == 'l'){
			it_print(&file_list);
		}
		else if (op == 't'){
			ibt_print(tree);
		}
		else if (op == 'p'){
			printf("Insira o nome do arquivo a ser printado:\n");
			scanf("%*c%[^\n]", filename);
			file_print(&file_list, tree, filename);
		}
		else if (op == 'i'){
			printf("Insira o nome do arquivo:\n");
			scanf("%*c%[^\n]", filename);
			printf("Insira o conteúdo a ser adicionado:\n");
			scanf("%*c%[^\n]", content);
			printf("Insira a posição (começando do 0):\n");
			scanf("%d", &pos);

			file.filename = strdup(filename);
			file.content = strdup(content);

			tree = file_add_text(&file_list, tree, t, file, max_buffer, pos);
		}
	}
	free(content);
	free(filename);
	free(newfile_name);
	free(newfile_content);	
	ibt_print(tree);
	it_clear(&file_list);
	ibt_clear(tree);
}

int	main(void)
{
	test_insert_file();
	return (0);
}
