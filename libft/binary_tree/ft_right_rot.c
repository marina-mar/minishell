/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:05:07 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/03 18:05:09 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

t_bst	*right_rotation(t_bst *grandfather, t_bst *father)
{
	t_bst *tmp;

	tmp = father->right;
	father->right = grandfather;
	grandfather->left = tmp;
	return (father);
}
