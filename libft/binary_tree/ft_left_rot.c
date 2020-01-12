/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:05:21 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/03 18:05:23 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

t_bst	*left_rotation(t_bst *grandfather, t_bst *father)
{
	t_bst	*tmp;

	tmp = father->left;
	father->left = grandfather;
	grandfather->right = tmp;
	return (father);
}
