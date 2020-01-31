/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_anything.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:53:00 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/31 14:52:00 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            write_anything(t_cw *corewar, t_parse *parser, int *i)
{
    char		*line;
	int			j;

	line = ft_strnew(1);
	j = 0;
	while (corewar->line[(*i)])
	{
		if (ft_isspace(corewar->line[(*i)]) || corewar->line[(*i)] == '"'
			|| corewar->line[(*i)] == '\0')
			break ;
		ft_join_char_free(&line, corewar->line[(*i)]);
		(*i)++;
	}
    check_str(corewar, parser, line);
}
