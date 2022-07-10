/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_block.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:00:02 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 09:40:34 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BLOCK_H
# define DATA_BLOCK_H
# include <stdlib.h>

typedef struct s_datablock
{
	int		id;
	int		previous_id;
	int		next_id;
	char	*content;
}				t_db;

t_db	*db_new(int id, int previous_id, char *content);
void	db_del(t_db *target);
int		db_getid();
#endif
