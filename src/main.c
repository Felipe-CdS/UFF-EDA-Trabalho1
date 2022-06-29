/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:34:57 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/06/29 16:38:12 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TARVB.h"
#include "TLSE.h"
#include "inode_table.h"
#include "inode_tree.h"

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
}

static void test_itree()
{
	int t;
	t_db *db1, *db2, *db3, *db4, *db5, *db6;
	t_itree *start;

	t = 2;
	db1 = (t_db *) malloc(sizeof(t_db));
	db1->id = 1;
	db2 = (t_db *) malloc(sizeof(t_db));
	db2->id = 2;
	db3 = (t_db *) malloc(sizeof(t_db));
	db3->id = 3;
	db4 = (t_db *) malloc(sizeof(t_db));
	db4->id = 4;
	db5 = (t_db *) malloc(sizeof(t_db));
	db5->id = 5;
	db6 = (t_db *) malloc(sizeof(t_db));
	db6->id = 6;


	start = ibt_new(t);
	start = ibt_insert(start, db1, t);	
	start = ibt_insert(start, db2, t);	
	start = ibt_insert(start, db3, t);	
	start = ibt_insert(start, db4, t);	
	start = ibt_insert(start, db5, t);	
	start = ibt_insert(start, db6, t);	
	ibt_print(start);
	ibt_clear(start);
}

int	main(void)
{
	test_itable();
	test_itree();
	return (0);
}
