/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:35:03 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/31 16:08:21 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            second_part_parse(t_cw *corewar, t_parse *parser, int *i)
{
	while (corewar->line[(*i)])
	{
		if (ft_isspace(corewar->line[(*i)]))
			skip_spaces(corewar, i);
		else if (separators(corewar->line[(*i)]))
			skip_separators(corewar, i);
		else
			who_is_who(corewar, parser, i);
		if (corewar->line[(*i)] == '\n')
			new_line(corewar);
	}
}
