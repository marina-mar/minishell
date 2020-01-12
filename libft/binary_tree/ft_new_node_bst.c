/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node_bst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 22:48:02 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/17 22:48:03 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

t_bst	*ft_new_node_bst(void *data)
{
	t_bst	*new_node;

	new_node = ft_memalloc(sizeof(t_bst));
	new_node->content = data;
	new_node->right = NULL;
	new_node->left = NULL;
	return (new_node);
}
