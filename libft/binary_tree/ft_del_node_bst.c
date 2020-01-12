/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_node_bst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 00:43:01 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/01 19:19:20 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/binary_tree.h"

t_bst	*delete_no_child(t_bst *node, t_bst *father)
{
	if (father->left == node)
		father->left = NULL;
	else
		father->right = NULL;
	ft_memdel((void**)&node);
	return (father);
}

t_bst	*delete_w_one_child(t_bst *node, t_bst *father)
{
	t_bst	*child;

	if (node->right != NULL)
		child = node->right;
	else
		child = node->left;
	if (father->left == node)
		father->left = child;
	else
		(father->right = child);
	ft_memdel((void**)&node);
	return (father);
}

t_bst	*ft_set_right_left(t_bst *last, t_bst *father, t_bst *node)
{
	if (father->left == last)
	{
		if (node->right != last)
			(father->left)->right = node->right;
		else
			(father->left)->right = NULL;
		if (node->left != last)
			(father->left)->left = node->left;
		else
			(father->left)->left = NULL;
	}
	else
	{
		if (node->right != last)
			(father->right)->right = node->right;
		else
			(father->right)->right = NULL;
		if (node->left != last)
			(father->right)->left = node->left;
		else
			(father->right)->left = NULL;
	}
	return (father);
}

t_bst	*delete_w_two_child(t_bst *node, t_bst *father, t_bst *root)
{
	t_bst	*last;
	t_bst	*father_last;

	if (father->left == node)
		last = ft_find_min(root);
	else
		last = ft_find_max(root);
	father_last = ft_find_father(last, root);
	if (father->left == node)
		father->left = last;
	else
		father->right = last;
	father = ft_set_right_left(last, father, node);
	if (father_last->left == last)
		father_last->left = NULL;
	else
		father_last->right = NULL;
	ft_memdel((void**)&node);
	return (father);
}

t_bst	*ft_del_node_bst(t_bst *node, t_bst *root)
{
	t_bst	*father;

	father = ft_find_father(node, root);
	if (node->right == NULL && node->left == NULL)
		father = delete_no_child(node, father);
	else if ((node->right != NULL && node->left == NULL) ||
			(node->right == NULL && node->left != NULL))
		father = delete_w_one_child(node, father);
	else
		father = delete_w_two_child(node, father, root);
	return (root);
}
