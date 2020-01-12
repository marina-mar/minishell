/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 04:33:02 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/17 04:33:05 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

t_bst	*add_bst(t_bst *new, t_bst **root, int (*f)(void*, void*))
{
	if (*root == NULL)
		*root = new;
	else if (f(new, *root) >= 0)
	{
		if ((*root)->right == NULL)
			(*root)->right = new;
		else
			add_bst(new, &((*root)->right), f);
	}
	else
	{
		if ((*root)->left == NULL)
			(*root)->left = new;
		else
			add_bst(new, &((*root)->left), f);
	}
	return (*root);
}
