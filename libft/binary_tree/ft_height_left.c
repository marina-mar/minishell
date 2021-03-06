/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_height_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 23:26:14 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/18 23:26:15 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

static int	ft_height(t_bst *root)
{
	int	height_left;
	int	height_r;
	int	height_l;

	height_left = 0;
	height_r = 0;
	height_l = 0;
	if (root == NULL)
		return (-1);
	height_r = height_r + ft_height(root->right);
	height_l = height_l + ft_height(root->left);
	if (height_r >= height_l)
		(height_left = height_left + height_r);
	else
		(height_left = height_left + height_l);
	return (height_left + 1);
}

int			ft_height_left(t_bst *root)
{
	int	height_left;

	height_left = ft_height(root->left);
	return (height_left + 1);
}
