/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_father.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 22:23:28 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/19 22:23:30 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

t_bst	*ft_find_father(t_bst *node, t_bst *root)
{
	t_bst	*tmp;

	tmp = root;
	while (root->left != NULL)
	{
		if (root->left == node)
			return (root);
		else
			root = root->left;
	}
	root = tmp;
	while (root->right != NULL)
	{
		if (root->right == node)
			return (root);
		else
			root = root->right;
	}
	return (NULL);
}
