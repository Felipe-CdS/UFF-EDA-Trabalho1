/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_block.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:00:02 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/05 10:45:57 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_BLOCK
# define DATA_BLOCK
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
#endif
