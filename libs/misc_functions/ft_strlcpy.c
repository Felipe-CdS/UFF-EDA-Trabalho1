/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:48:20 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 09:48:52 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc_functions.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (!src[i] || dstsize == 1)
	{
		dst[i] = '\0';
		return (strlen(src));
	}
	while (src[i] && i < dstsize)
	{
		dst[i] = src[i];
		++i;
		if (!src[i] || i == dstsize - 1)
		{
			dst[i] = '\0';
			break ;
		}
	}
	return (strlen(src));
}