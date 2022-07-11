/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 22:32:26 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 22:40:04 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc_methods.h"

static int	check_start(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;

	i = 0;
	if (!len)
	{
		return (0);
	}
	while (i < start)
	{
		if (!s[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static size_t	min_size(char const *s, size_t len)
{
	size_t	size;

	size = strlen(s) + 1;
	if ((len + 1) < size)
		return (len + 1);
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	size_t			malloc_size;

	i = 0;
	if (!s)
		return (NULL);
	malloc_size = min_size(s, len);
	substr = (char *) malloc(sizeof(char) * malloc_size);
	if (!substr)
		return (NULL);
	if (!check_start(s, start, len))
	{
		ft_strlcpy(substr, "", 1);
		return (substr);
	}
	while (s[(start + i)] && i < len)
	{
		substr[i] = s[(i + start)];
		++i;
	}
	substr[i] = '\0';
	return (substr);
}