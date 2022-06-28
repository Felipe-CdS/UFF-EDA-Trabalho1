/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inode_table.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:18:25 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/06/27 19:13:09 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INODE_TABLE_H
# define INODE_TABLE_H
# include <stdio.h>
# include <stdlib.h>

typedef struct s_itable
{
	int					id;
	char				*filename;
	struct s_itable 	*next;
}				t_itable;

t_itable	*it_new(int id, char *filename);
t_itable	*it_last(t_itable *start);

void		it_add_front(t_itable **start, t_itable *new);
void		it_add_back(t_itable **start, t_itable *new);
void		it_delone(t_itable **start, t_itable *target);
void		it_clear(t_itable **start);
void		it_print(t_itable **start);

int			it_size(t_itable *start);
#endif
