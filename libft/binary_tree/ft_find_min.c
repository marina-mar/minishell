/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 22:38:19 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/17 22:38:22 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

t_bst	*ft_find_min(t_bst *root)
{
	if (root == NULL)
		return (NULL);
	if (root->left == NULL)
		return (root);
	return (ft_find_min(root->left));
}
