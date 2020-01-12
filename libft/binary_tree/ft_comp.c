/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 22:53:43 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/17 22:53:52 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

int	ft_comp(void *new_node, void *root)
{
	int		new;
	int		r;
	t_bst	*node_new;
	t_bst	*origin;

	node_new = (t_bst*)new_node;
	origin = (t_bst*)root;
	new = *(int*)node_new->content;
	r = *(int*)origin->content;
	if (new > r)
		return (1);
	else if (new < r)
		return (-1);
	else
		return (0);
}
