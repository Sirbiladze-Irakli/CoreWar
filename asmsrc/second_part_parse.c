/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:35:03 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/05 20:08:39 by jormond-         ###   ########.fr       */
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
	compare_labels(corewar, parser);
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
		ErrorOut(corewar, SEPARATOR_ERROR);
	if (parser->commas > 0)
		ErrorOut(corewar, END_LINE_ERROR);
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
	char		*toFind;

	parser->j = 0;
	if (arg->label == DIRECT_LABEL)
		toFind = ft_strsub(arg->token, 2, ft_strlen(arg->token) - 1);	
	else if (arg->label == INDIRECT_LABEL)
		toFind = ft_strsub(arg->token, 1, ft_strlen(arg->token) - 1);
	while (corewar->labels[parser->j])
	{
		if (!ft_strcmp(toFind, corewar->labels[parser->j++]))
		{
			free(toFind);
			return ;
		}
	}
	wrong_instr(corewar, arg, toFind);
	free(toFind);
	exit(0);
}

// void			wrong_way(t_cw *corewar, t_parse *parser, t_ls *tmp, char *str)
// {
	
// }
