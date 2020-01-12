/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 22:38:39 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/17 22:38:43 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

t_bst	*ft_find_max(t_bst *root)
{
	if (root == NULL)
		return (NULL);
	if (root->right == NULL)
		return (root);
	return (ft_find_max(root->right));
}
