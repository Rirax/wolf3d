/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 15:16:45 by rlechapt          #+#    #+#             */
/*   Updated: 2014/11/13 17:25:31 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(int n)
{
	int				i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int				i;
	int				sign;
	char			*s;
	unsigned int	nb;

	sign = 0;
	nb = n;
	if (n < 0)
	{
		sign = 1;
		nb = -n;
	}
	i = ft_digit_count(n);
	if ((s = (char *)ft_memalloc(i + sign + 1)) == NULL)
		return (NULL);
	while (i--)
	{
		s[i + sign] = (nb % 10) + '0';
		nb /= 10;
	}
	if (sign == 1)
		s[0] = '-';
	return (s);
}
