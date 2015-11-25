/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:59:41 by rlechapt          #+#    #+#             */
/*   Updated: 2014/11/13 20:01:58 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	char	*s2;
	int		start;
	int		len;
	int		i;

	start = 0;
	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	start = i;
	len = ft_strlen(s);
	i = len - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i >= start)
		i--;
	if ((s2 = ft_strsub(s, start, (i - start + 1))) == NULL)
		return (NULL);
	return (s2);
}
