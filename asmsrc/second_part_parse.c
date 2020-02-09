/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:35:03 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/09 18:26:38 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			second_part_parse(t_cw *corewar, t_parse *parser, int *i)
{
	while (corewar->line[(*i)])
	{
		// printf("%c", corewar->line[(*i)]);
		if (parser->commas == (parser->args * -1 - 2))
			ft_errors(corewar);
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
	parser->commas--;
	if (parser->args > 0)
		parser->comflag = 1;
	skip_separators(corewar, i);
	if (corewar->line[(*i)] == ',')
		errors_out(corewar, SEPARATOR_ERROR);
	if (parser->commas < 0)
		errors_out(corewar, END_LINE_ERROR);
}

void			compare_labels(t_cw *corewar, t_parse *parser)
{
	t_ls		*arg;

	arg = corewar->tokens;
	while (corewar->tokens)
	{
		if (corewar->tokens->label == 104 || corewar->tokens->label == 107)
			compare(corewar, parser, corewar->tokens);
		corewar->tokens = corewar->tokens->next;
	}
	corewar->tokens = arg;
}

void			compare(t_cw *corewar, t_parse *parser, t_ls *arg)
{
	char		*to_find;

	parser->j = 0;
	if (arg->label == DIRECT_LABEL)
		to_find = ft_strsub(arg->token, 2, ft_strlen(arg->token) - 1);
	else if (arg->label == INDIRECT_LABEL)
		to_find = ft_strsub(arg->token, 1, ft_strlen(arg->token) - 1);
	while (corewar->labels[parser->j])
	{
		if (!ft_strcmp(to_find, corewar->labels[parser->j++]))
		{
			free(to_find);
			return ;
		}
	}
	wrong_instr(arg, to_find);
	free(to_find);
	exit(0);
}
