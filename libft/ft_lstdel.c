/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlechapt <rlechapt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/02 04:37:06 by rlechapt          #+#    #+#             */
/*   Updated: 2015/04/02 06:43:03 by rlechapt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	if (!alst)
		return ;
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(*alst);
	}
	tmp = NULL;
}
