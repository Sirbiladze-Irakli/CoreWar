/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:35:03 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/04 19:35:17 by jormond-         ###   ########.fr       */
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
	t_ls		*label;

	arg = corewar->tokens;
	printf("%s arg\n", arg->token);
	label = corewar->labels;
	printf("%s label\n", label->token);
	while (arg)
	{
		printf("!\n");
		if (arg->label >= 104 && arg->label <= 109)
		{
			while (label)
			{
				printf("whats wrong\n");
				if (!ft_strnstr(arg->token, label->token, (ft_strlen(label->token) - 1)))
					break ;
				if (label->next == NULL)
					wrong_instr(corewar, arg, arg->token);
				label = label->next;
			}
			label = label->prev;
			while (label->prev)
				label = label->prev;
		}
		arg = arg->next;
	}
	arg = arg->prev;
	
}

void			wrong_way(t_cw *corewar, t_parse *parser, t_ls *tmp, char *str)
{
	
}
