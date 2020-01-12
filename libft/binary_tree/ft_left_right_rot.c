/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_right_rot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:05:33 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/03 18:05:35 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

t_bst	*left_right_rot(t_bst *gfather, t_bst *father, t_bst *kid)
{
	t_bst *tmp;

	tmp = kid->left;
	gfather->left = kid;
	kid->left = father;
	father->right = tmp;
	return (right_rotation(gfather, gfather->left));
}
