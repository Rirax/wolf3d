/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 10:20:23 by rlechapt          #+#    #+#             */
/*   Updated: 2014/11/11 21:57:06 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < (int)size)
		i++;
	start = i;
	while (src[j] != '\0' && i < (int)size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i > start)
		dst[i] = '\0';
	return (start + ft_strlen((char*)src));
}
