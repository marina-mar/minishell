/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeIntArr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 05:42:33 by mcouto            #+#    #+#             */
/*   Updated: 2019/05/14 21:42:13 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_makeintarr(int howmany, int **zipline)
{
	int *ret;

	if (!(ret = ft_memalloc(sizeof(int) * howmany)))
		return ;
	*zipline = ret;
}
