/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 13:42:37 by rlechapt          #+#    #+#             */
/*   Updated: 2015/04/02 01:12:54 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			if (s[i] == c || s[i] == '\0')
				j++;
		}
	}
	return (j);
}

static int	ft_word_size(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nbrw;
	int		j;
	int		i;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	nbrw = ft_word_count(s, c);
	if ((tab = (char**)malloc(sizeof(char *) * (nbrw + 1))) == NULL)
		return (NULL);
	while (j < nbrw)
	{
		while (s[i] == c && s[i])
			i++;
		if ((tab[j] = ft_strsub(s, i, ft_word_size(s, c, i))) == NULL)
			return (NULL);
		i += ft_word_size(s, c, i);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
