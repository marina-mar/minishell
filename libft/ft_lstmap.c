/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 07:04:06 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/14 21:44:25 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*final;

	if (!lst || !f)
		return (NULL);
	final = f(lst);
	temp = final;
	lst = lst->next;
	while (lst)
	{
		final->next = f(lst);
		final = final->next;
		lst = lst->next;
	}
	return (temp);
}
