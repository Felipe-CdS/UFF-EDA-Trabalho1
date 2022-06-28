/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:34:57 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/06/27 19:26:16 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TARVB.h"
#include "TLSE.h"
#include "inode_table.h"

int	main(void)
{
	t_itable	*start;

	start =	NULL;
	it_add_back(&start, it_new(1, "a.txt"));
	it_add_back(&start, it_new(12, "b.jpg"));
	it_add_back(&start, it_new(99, "File_1.png"));
	it_add_back(&start, it_new(5, "random.mp4"));
	it_add_back(&start, it_new(2, "zzz.bin"));
	it_print(&start);
	return (0);
}
