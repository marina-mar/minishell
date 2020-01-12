/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iter_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 04:45:10 by mcouto            #+#    #+#             */
/*   Updated: 2019/08/17 04:45:14 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

void	ft_iterate_tree(t_bst **root, void (*f)(t_bst **root))
{
	if (*root == NULL)
		return ;
	ft_iterate_tree(&((*root)->left), f);
	f(root);
	ft_iterate_tree(&((*root)->right), f);
}
