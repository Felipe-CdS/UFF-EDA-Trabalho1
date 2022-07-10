/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:04:27 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 15:56:14 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc_methods.h"

static int	check_needle(char *n_ptr, char *s_ptr, unsigned int h, size_t len)
{
	unsigned int	i;

	i = 0;
	while (n_ptr[i] && s_ptr[i] == n_ptr[i])
	{
		if (h + i >= len)
		{
			return (0);
		}
		i++;
	}
	if (!n_ptr[i])
	{
		return (1);
	}
	return (0);
}

static char	*search(char *h_ptr, char *n_ptr, char *s_ptr, size_t len)
{
	unsigned int	h_iter;

	h_iter = 0;
	while (h_ptr[h_iter] && h_iter < len)
	{		
		if (h_ptr[h_iter] == n_ptr[0])
		{
			s_ptr = &h_ptr[h_iter];
			if (check_needle(n_ptr, s_ptr, h_iter, len))
			{
				return (s_ptr);
			}
		}
		s_ptr = NULL;
		h_iter++;
	}
	return (s_ptr);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char			*n_ptr;
	char			*h_ptr;
	char			*s_ptr;

	n_ptr = (char *) needle;
	h_ptr = (char *) haystack;
	s_ptr = NULL;
	if (!(*n_ptr))
	{
		return (h_ptr);
	}
	s_ptr = search(h_ptr, n_ptr, s_ptr, len);
	return (s_ptr);
}