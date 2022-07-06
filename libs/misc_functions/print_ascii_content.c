/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ascii_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:22:54 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/06 13:58:00 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	This function goes inside ibt_print to improve printf.
*	It detects any non-printable char and prints '.' instead.
*	This can prevent any '\n' or '\t' inside the file breaking 
*	the tree print formating.
*/
#include "misc_functions.h"

static int	ft_isprint(unsigned char c)
{
	if ((c >= 32 && c <= 126) || (c >= 128))
	{
		return (1);
	}
	return (0);
}

void	print_ascii_content(char *content)
{
	int	i;

	i = 0;
	while(content[i])
	{
		if(ft_isprint(content[i]))
			printf("%c", content[i]);
		else
			printf(".");
		i++;
	}
}


