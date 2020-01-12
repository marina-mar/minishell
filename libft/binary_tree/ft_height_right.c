/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_height_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 23:26:21 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/18 23:26:23 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

static int	ft_height(t_bst *root)
{
	int	height_right;
	int	height_r;
	int	height_l;

	height_right = 0;
	height_r = 0;
	height_l = 0;
	if (root == NULL)
		return (-1);
	height_r = height_r + ft_height(root->right);
	height_l = height_l + ft_height(root->left);
	if (height_r >= height_l)
		(height_right = height_right + height_r);
	else
		(height_right = height_right + height_l);
	return (height_right + 1);
}

int			ft_height_right(t_bst *root)
{
	int	height_right;

	height_right = ft_height(root->right);
	return (height_right + 1);
}
