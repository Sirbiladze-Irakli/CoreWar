/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:02:16 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/06 17:07:37 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			parse(t_cw *corewar)
{
	int		i;
	t_parse	parser;

	i = 0;
	check_EOF(corewar, &i);
	init_parser(&parser);
	first_part_parse(corewar, &parser, &i);
	second_part_parse(corewar, &parser, &i);
	compare_labels(corewar, &parser);
	// while (corewar->tokens)
	// {
	//     printf("\n%p - tokens\n", corewar->tokens);
	// 	printf("|%s| - value\n", corewar->tokens->token);
	// 	printf("%d - label\n", corewar->tokens->label);
	// 	if (corewar->tokens->next == NULL)
	// 		break ;
	//     corewar->tokens = corewar->tokens->next;
	// }
	// while (corewar->tokens)
	// {
	// 	if (corewar->tokens->prev == NULL)
	// 		break ;
	// 	corewar->tokens = corewar->tokens->prev;
	// }
}

void			init_parser(t_parse *parser)
{
	parser->i = 0;
	parser->j = 0;
	parser->quotes = 0;
	parser->first_dot = 0;
	parser->name = 0;
	parser->comment = 0;
	parser->args = 0;
	parser->order = 0;
	parser->commas = 0;
	parser->comflag = 0;
	parser->countArgs = 0;
}

void			first_part_parse(t_cw *corewar, t_parse *parser, int *i)
{
	while (corewar->line[(*i)])
	{
		if (ft_isspace(corewar->line[(*i)]))
			skip_spaces(corewar, i);
		else if (separators(corewar->line[(*i)]))
			skip_separators(corewar, i);
		if (corewar->line[(*i)] == '.')
			command(corewar, parser, i);
		else if (!ft_isspace(corewar->line[(*i)]) && parser->comment == 1
			&& parser->name == 1)
			return ;
		else if (!ft_isspace(corewar->line[(*i)]))
			write_anything(corewar, parser, i);
		if (corewar->line[(*i)] == '\n')
			new_line(corewar);
		corewar->esym++;
		(*i)++;
	}
}

void			command(t_cw *corewar, t_parse *parser, int *i)
{
	if (parser->first_dot == 0)
		fill_commands(corewar, parser, i);
	else if (parser->first_dot == 1 && (parser->comment != 1
		|| parser->name != 1))
		fill_commands(corewar, parser, i);
	else if (parser->comment >= 1 && parser->name >= 1)
		bad_line(corewar, parser, i);
}

void			fill_commands(t_cw *corewar, t_parse *parser, int *i)
{
	char		*line;
	int			j;

	line = ft_strnew(1);
	j = 0;
	if (parser->first_dot != 3)
		parser->first_dot++;
	while (corewar->line[(*i)])
	{
		if (ft_isspace(corewar->line[(*i)]) || corewar->line[(*i)] == '"'
			|| corewar->line[(*i)] == '\0')
			break ;
		ft_join_char_free(&line, corewar->line[(*i)]);
		corewar->esym++;
		(*i)++;
	}
	compare_val(corewar, parser, line, i);
	before_new_line(corewar, parser, i);
	free(line);
}
