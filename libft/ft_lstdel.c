/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 22:36:54 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/14 21:16:25 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tofree;

	if (!alst || !del)
		return ;
	else
	{
		while ((*alst)->next != NULL)
		{
			tofree = *alst;
			ft_lstdelone(alst, del);
			*alst = tofree->next;
		}
		if ((*alst)->next == NULL)
		{
			ft_lstdelone(alst, del);
		}
	}
}
