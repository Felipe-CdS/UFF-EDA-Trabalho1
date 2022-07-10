/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_multi_lines_stdin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:27:51 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 16:28:59 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc_methods.h"

void	get_multi_lines_stdin(char **str)
{
	int i = 1;
	int t = 0;
	char c;

    while(1){
        if((c = getchar()) != ';')
		{
            (*str) = realloc((*str), i * sizeof(char));
            *((*str)+t) = c;
            t++;
            i++;
        } else 
		{
            (*str) = realloc((*str), i * sizeof(char));
            *((*str)+t) = '\0';
            break;
        }
    }
}