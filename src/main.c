/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:34:57 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/06/29 17:35:10 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TARVB.h"
#include "TLSE.h"
#include "inode_table.h"
#include "inode_tree.h"
#include "data_block.h"
#include <string.h>

static void test_itable()
{
	t_itable	*start;

	start =	NULL;
	it_add_back(&start, it_new(1, "a.txt"));
	it_add_back(&start, it_new(12, "b.jpg"));
	it_add_back(&start, it_new(99, "File_1.png"));
	it_add_back(&start, it_new(5, "random.mp4"));
	it_add_back(&start, it_new(2, "zzz.bin"));
	it_print(&start);
	it_clear(&start);
	printf("\n\n");
}

static void test_itree()
{
	int t;
	char *a, *b, *c, *d, *e, *f;
	t_db *db1, *db2, *db3, *db4, *db5, *db6;
	t_itree *start;

	t = 2;
	
	a = strdup("Lorem");
	db1 = db_new(55, -1, &a);
	b = strdup("ipsum");
	db2 = db_new(62, -1, &b);
	c = strdup("dolor");
	db3 = db_new(30, -1, &c);
	d = strdup("sit");
	db4 = db_new(2, -1, &d);
	e = strdup("amet");
	db5 = db_new(15, -1, &e);
	f = strdup("consectetur");
	db6 = db_new(1, -1, &f);

	start = ibt_new(t);
	start = ibt_insert(start, db1, t);	
	start = ibt_insert(start, db2, t);	
	start = ibt_insert(start, db3, t);	
	start = ibt_insert(start, db4, t);	
	start = ibt_insert(start, db5, t);	
	start = ibt_insert(start, db6, t);	
	ibt_print(start);
	ibt_clear(start);
	printf("\n\n");
}

int	main(void)
{
	test_itable();
	test_itree();
	return (0);
}
