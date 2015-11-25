/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 10:18:23 by rlechapt          #+#    #+#             */
/*   Updated: 2014/11/13 19:54:26 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	if ((str = malloc(sizeof(*str) * (size))) == NULL)
		return (NULL);
	while (i < size)
	{
		((char *)str)[i] = '\0';
		i++;
	}
	return (str);
}
