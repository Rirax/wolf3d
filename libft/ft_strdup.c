/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 19:33:00 by rlechapt          #+#    #+#             */
/*   Updated: 2014/11/13 19:28:53 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if ((s2 = (char*)malloc(sizeof(*s2) * (ft_strlen(s1)))) == NULL)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}
