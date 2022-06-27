/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:34:57 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/06/27 13:02:48 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TARVB.h"
#include "TLSE.h"

int	main(void)
{
	TLSE	*x;
	TARVB	*y;

	(void) x;
	x = TLSE_inicializa();
	y = TARVB_Inicializa();

	TLSE_libera(x);
	TARVB_Libera(y);
	return (0);
}
