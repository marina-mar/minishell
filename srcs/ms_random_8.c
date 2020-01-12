/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_random_8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouto <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 15:13:40 by mcouto            #+#    #+#             */
/*   Updated: 2019/10/01 15:13:41 by mcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ms_random(void)
{
	uintmax_t random;

	random = rand();
	if (random == 42)
		return ("~ *l * u * c * k * y * ~");
	else if (random <= 500000)
		return ("~ maybe ~");
	else if (random > 500000 && random < 1000000)
		return ("~~* this is a hard one, but I would say \"yes!\"**");
	else if (random > 500000 && random < 900000000)
		return ("~ . ~ ~ no");
	else if (random >= 900000000 && random < 1000000000)
		return (". . . it depends on the weather . . . ~");
	if (random >= 1000000000 && random < 1500000000)
		return ("~~ yes ~ *");
	if (random >= 1500000000 && random < 1700000000)
		return ("*~ I'm getting mixed signals about that... ~");
	if (random >= 1700000000 && random < 1800000000)
		return ("zzz ooh.... im sleeping now zzzz try later ~~");
	if (random >= 1800000000 && random <= 2000000000)
		return (".*.*.maybe.*.*.");
	else
		return ("those questions only the future can answer *~");
}

void		ms_random_8(void)
{
	ft_printf("%B|%E %Y     %Y_____   %E*\n"\
	"%B|%E   %Y  /  __ \\%E*    %E\n"\
	"%B|%E  %Y  |   (8) |  %E*%Y  %E\n"\
	"%B|%E %Y    \\   - /  %s   %E\n\%"
	"B|%E %YTTTTTTTTTTTTTTTTT%E\n", ms_random());
}
