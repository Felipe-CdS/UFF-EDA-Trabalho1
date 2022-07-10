/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:47:23 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 09:48:18 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc_functions.h"

static unsigned int	min(unsigned int x, unsigned int y)
{
	if (x <= y)
	{
		return (x);
	}
	return (y);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	total_size;

	if (!dstsize)
	{
		return (strlen(src));
	}
	total_size = min(strlen(dst), dstsize) + strlen(src);
	i = strlen(dst);
	if (i >= (dstsize - 1))
	{
		return (total_size);
	}
	ft_strlcpy(&dst[i], src, (dstsize - i));
	return (total_size);
}