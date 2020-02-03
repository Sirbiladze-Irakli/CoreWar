/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:35:03 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/03 17:15:50 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            second_part_parse(t_cw *corewar, t_parse *parser, int *i)
{
	while (corewar->line[(*i)])
	{
		if (parser->commas == (parser->args * -1 - 2))
			ft_errors(corewar, parser);
		if (ft_isspace(corewar->line[(*i)]))
			space_check(corewar, parser, i);
		else if (separators(corewar->line[(*i)]))
			separator_check(corewar, parser, i);
		else
			who_is_who(corewar, parser, i);
	}
}

void			space_check(t_cw *corewar, t_parse *parser, int *i)
{
	check_instr(corewar, parser, i);
	if (corewar->line[(*i)] == '\n')
		new_line(corewar);
	(*i)++;
	corewar->esym++;
}

void			separator_check(t_cw *corewar, t_parse *parser, int *i)
{

	parser->commas++;
	if (parser->args > 0)
		parser->comflag = 1;
	skip_separators(corewar, i);
	if (corewar->line[(*i)] == ',')
		ErrorOut(corewar, parser, SEPARATOR_ERROR);
	if (parser->commas > 0)
		ErrorOut(corewar, parser, END_LINE_ERROR);
}

void			wrong_way(t_cw *corewar, t_parse *parser, t_ls *tmp, char *str)
{
	
}
