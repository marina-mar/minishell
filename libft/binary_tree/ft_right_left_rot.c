/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_left_rot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:05:46 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/03 18:05:47 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

t_bst	*right_left_rot(t_bst *gfather, t_bst *father, t_bst *kid)
{
	t_bst *tmp;

	tmp = kid->right;
	gfather->right = kid;
	kid->right = father;
	father->left = tmp;
	return (left_rotation(gfather, gfather->right));
}
