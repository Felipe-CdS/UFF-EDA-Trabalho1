/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_single_line_stdin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:53:54 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 15:55:48 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc_methods.h"

void get_single_line_stdin(char **str)
{
	int i = 1;
	int t = 0;
	char c;

    while(1){
        if((c = getchar()) != '\n')
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