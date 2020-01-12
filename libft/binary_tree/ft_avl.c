/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:37:22 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/19 16:37:24 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

t_bst	*right_hand(t_bst *grandfather)
{
	t_bst	*father;

	father = grandfather->right;
	if (father->left == NULL)
		grandfather = left_rotation(grandfather, father);
	else
		grandfather = right_left_rot(grandfather, father, father->left);
	return (grandfather);
}

t_bst	*left_hand(t_bst *grandfather)
{
	t_bst	*father;

	father = grandfather->left;
	if (father->right == NULL)
		grandfather = right_rotation(grandfather, father);
	else
		grandfather = left_right_rot(grandfather, father, father->right);
	return (grandfather);
}

t_bst	*ft_rotate(t_bst *node)
{
	int	height_right;
	int	height_left;
	int	dif;

	height_left = ft_height_left(node);
	height_right = ft_height_right(node);
	if (height_left >= height_right)
		dif = height_left - height_right;
	else
		dif = height_right - height_left;
	if (dif > 1)
	{
		if (height_left > height_right)
			node = left_hand(node);
		else
			node = right_hand(node);
	}
	return (node);
}

void	ft_avl(t_bst **root)
{
	if (*root == NULL)
		return ;
	ft_avl(&((*root)->left));
	ft_avl(&((*root)->right));
	*root = ft_rotate(*root);
}
