/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_start_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:13:41 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 12:48:18 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_methods.h"

void	menu_start_routine(t_itree  **tree, t_itable **file_list, int *t, int *MAX_BLOCK_BUFFER, char *op)
{
	*op = '\0';
	printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
	scanf("%d", t);	
	if(*t < 2) 
		*t = 2;
	printf("Digite o tamanho máximo de uma string em cada bloco de um inode:\n");
	scanf("%d", MAX_BLOCK_BUFFER);	
	*tree = NULL;
	*file_list = NULL;
}