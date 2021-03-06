/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoutinh <felipe_coutinho@id.uff.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 09:26:22 by fcoutinh          #+#    #+#             */
/*   Updated: 2022/07/10 20:22:16 by fcoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc_methods.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	buffer_size;

	if(!s1)
		s1 = "";
	if(!s2)
		s2 = "";	

	buffer_size = sizeof(char) * (strlen(s1) + strlen(s2) + 1);
	dst = (char *) malloc(buffer_size);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, buffer_size);
	ft_strlcat(dst, s2, buffer_size);
	return (dst);
}