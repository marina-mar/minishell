/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_height_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 23:25:57 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/18 23:26:03 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

int	ft_height_max(t_bst *root)
{
	int height_left;
	int height_right;

	height_left = 0;
	height_right = 0;
	if (root == NULL)
		return (-1);
	height_right = height_right + ft_height_max(root->right);
	height_left = height_left + ft_height_max(root->left);
	return ((height_left >= height_right) ? height_left + 1 : height_right + 1);
}
