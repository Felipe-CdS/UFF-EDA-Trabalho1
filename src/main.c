/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:34:57 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/06 13:05:57 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inode_table.h"
#include "inode_tree.h"
#include "file_methods.h"
#include <string.h>
#include <ctype.h>

// static void test_itable()
// {
// 	t_itable	*start;

// 	start =	NULL;
// 	it_add_back(&start, it_new(1, "a.txt"));
// 	it_add_back(&start, it_new(12, "b.jpg"));
// 	it_add_back(&start, it_new(99, "File_1.png"));
// 	it_add_back(&start, it_new(5, "random.mp4"));
// 	it_add_back(&start, it_new(2, "zzz.bin"));
// 	it_print(&start);
// 	it_clear(&start);
// 	printf("\n\n");
// }

// static void test_itree()
// {
// 	int t;
// 	char *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *y, *u, *v, *x;
// 	t_db *db1, *db2, *db3, *db4, *db5, *db6, *db7, *db8, *db9, *db10, *db11, *db12, *db13, *db14, *db15, *db16, *db17, *db18, *db19, *db20, *db21, *db22, *db23;
// 	t_itree *start;

// 	t = 2;
	
// 	a = strdup("Lorem");
// 	db1 = db_new(20, -1, &a);
// 	b = strdup("ipsum");
// 	db2 = db_new(50, -1, &b);
// 	c = strdup("dolor");
// 	db3 = db_new(60, -1, &c);
// 	d = strdup("sit");
// 	db4 = db_new(1, -1, &d);
// 	e = strdup("amet");
// 	db5 = db_new(64, -1, &e);
// 	f = strdup("consectetur");
// 	db6 = db_new(12, -1, &f);
// 	g = strdup("consectetur");
// 	db7 = db_new(18, -1, &g);
// 	h = strdup("consectetur");
// 	db8 = db_new(66, -1, &h);
// 	i = strdup("consectetur");
// 	db9 = db_new(38, -1, &i);
// 	j = strdup("consectetur");
// 	db10 = db_new(95, -1, &j);
// 	k = strdup("consectetur");
// 	db11 = db_new(58, -1, &k);
// 	l = strdup("consectetur");
// 	db12 = db_new(59, -1, &l);
// 	m = strdup("consectetur");
// 	db13 = db_new(70, -1, &m);
// 	n = strdup("consectetur");
// 	db14 = db_new(68, -1, &n);
// 	o = strdup("consectetur");
// 	db15 = db_new(39, -1, &o);
// 	p = strdup("consectetur");
// 	db16 = db_new(62, -1, &p);
// 	q = strdup("consectetur");
// 	db17 = db_new(7, -1, &q);
// 	r = strdup("consectetur");
// 	db18 = db_new(55, -1, &r);
// 	s = strdup("consectetur");
// 	db19 = db_new(43, -1, &s);
// 	y = strdup("consectetur");
// 	db20 = db_new(16, -1, &y);
// 	u = strdup("consectetur");
// 	db21 = db_new(67, -1, &u);
// 	v = strdup("consectetur");
// 	db22 = db_new(34, -1, &v);
// 	x = strdup("consectetur");
// 	db23 = db_new(35, -1, &x);


// 	start = ibt_new(t);
// 	start = ibt_insert(start, db1, t);	
// 	start = ibt_insert(start, db2, t);	
// 	start = ibt_insert(start, db3, t);	
// 	start = ibt_insert(start, db4, t);	
// 	start = ibt_insert(start, db5, t);	
// 	start = ibt_insert(start, db6, t);
// 	start = ibt_insert(start, db7, t);	
// 	start = ibt_insert(start, db8, t);	
// 	start = ibt_insert(start, db9, t);	
// 	start = ibt_insert(start, db10, t);	
// 	start = ibt_insert(start, db11, t);	
// 	start = ibt_insert(start, db12, t);	
// 	start = ibt_insert(start, db13, t);	
// 	start = ibt_insert(start, db14, t);	
// 	start = ibt_insert(start, db15, t);	
// 	start = ibt_insert(start, db16, t);	
// 	start = ibt_insert(start, db17, t);	
// 	start = ibt_insert(start, db18, t);	
// 	start = ibt_insert(start, db19, t);	
// 	start = ibt_insert(start, db20, t);		
// 	start = ibt_insert(start, db21, t);
// 	start = ibt_insert(start, db22, t);	
// 	start = ibt_insert(start, db23, t);	

// 	start = ibt_remove(start, db2, t);
// 	start = ibt_remove(start, db10, t);
// 	start = ibt_remove(start, db13, t);
// 	start = ibt_remove(start, db3, t);
// 	start = ibt_remove(start, db23, t);	
// 	printf("1) %d | %p | %p | %s\n", (start->blocks[0])->id, (start->blocks[0]), ((start->blocks[0])->content), (*(start->blocks[0])->content));
// 	ibt_print(start);
// 	printf("5) %d | %p | %p | %s\n", (start->blocks[0])->id, (start->blocks[0]), ((start->blocks[0])->content), (*(start->blocks[0])->content));
// 	printf("\n\n");
// 	ibt_clear(start);
// }

static void test_insert_file()
{
	int			i, t, max_buffer, fsize;
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

	t = 2;
	i = 0;

	printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
	scanf("%d", &t);

	if(t < 2) t = 2;
	while(i != -1){
		printf("Escolha a operação (a: adicionar; r: remover)\n");
		scanf(" %c", &op);
		printf("\n");
		op = tolower(op);
		if(op == 'a'){
			printf("Deseja criar um arquivo novo? (s/n): ");
			scanf(" %c", &op);
			printf("\n");
			op = tolower(op);
			if(op == 's'){
				printf("Insira o nome do arquivo a ser criado: ");
				scanf("%*c%[^\n]", newfile_name);
				printf("\n");
				printf("Insira o conteúdo do arquivo: ");
				scanf("%*c%[^\n]", newfile_content);
				printf("\n");

				file.filename = strdup(newfile_name);
				file.content = strdup(newfile_content);

				tree = file_insert(&file_list, tree, t, file, max_buffer);
			}
			else if(op == 'n') {
				printf("Insira o nome do arquivo a ser carregado: ");
				scanf("%*c%[^\n]", filename);
				
				fp = fopen(filename, "r");
				if(!fp) printf("Arquivo não encontrado\n");
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
			printf("Insira o nome do arquivo a ser removido: ");
			scanf("%*c%[^\n]", filename);

			file_remove(&file_list, tree, t, filename);
		}

		it_print(&file_list);
		ibt_print(tree);
	}

	free(content);
	free(filename);
	free(newfile_name);
	free(newfile_content);
	
	it_print(&file_list);
	
	ibt_print(tree);
	it_clear(&file_list);
	ibt_clear(tree);
}

int	main(void)
{
	// test_itable();
	// test_itree();
	test_insert_file();
	return (0);
}
