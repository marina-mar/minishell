/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:47:10 by mcouto            #+#    #+#             */
/*   Updated: 2019/09/02 17:47:12 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct		s_bst
{
	void			*content;
	struct s_bst	*right;
	struct s_bst	*left;
}					t_bst;

t_bst				*ft_new_node_bst(void *data);
t_bst				*add_bst(t_bst *new, t_bst **root, int (*f)(void*, void*));
t_bst				*ft_find_min(t_bst *root);
t_bst				*ft_find_max(t_bst *root);
t_bst				*ft_del_node_bst(t_bst *node, t_bst *root);
t_bst				*ft_find_father(t_bst *node, t_bst *root);
int					ft_comp(void *new_node, void *root);
int					ft_height_max(t_bst *root);
int					ft_height_left(t_bst *root);
int					ft_height_right(t_bst *root);
void				ft_iterate_tree(t_bst **root, void (*f)(t_bst **root));
void				ft_avl(t_bst **root);
t_bst				*left_rotation(t_bst *grandfather, t_bst *father);
t_bst				*right_rotation(t_bst *grandfather, t_bst *father);
t_bst				*right_left_rot(t_bst *gfather, t_bst *father, t_bst *kid);
t_bst				*left_right_rot(t_bst *gfather, t_bst *father, t_bst *kid);

#endif
