/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_get_next_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 10:18:20 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 23:10:31 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "menu_methods.h"

void	menu_get_next_op(char *op)
{
	printf("Escolha uma operação: (a: adicionar; r: remover; l: printar lista; t: printar arvore; s: procurar str; i: inserir conteudo; p: printar arquivo; c: cortar str; f: salvar arquivo)\n");
	scanf(" %c", op);
	*op = tolower(*op);
}