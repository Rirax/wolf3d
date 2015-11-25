/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:48:04 by rlechapt          #+#    #+#             */
/*   Updated: 2014/11/11 22:03:41 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s2;

	s2 = (char*)s;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (char)c)
			return (s2 + i);
		i++;
	}
	return (NULL);
}
