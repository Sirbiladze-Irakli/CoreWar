/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:02:16 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/19 19:33:30 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// void			parse(t_cw *corewar)
// {
// 	int		i;

// 	i = 0;
// 	while (corewar->line[i])
// 	{
// 		if (ft_isspace(corewar->line[i]) || corewar->line[i] == ';' ||
// 			corewar->line[i] == '#')
// 			skip_spaces(corewar, &i);
// 		else if (corewar->line[i] == '.')
// 			dot_label(corewar, &i);
// 		else if (corewar->line[i] == '"')
// 			token_in_quotes(corewar, &i);
// 		else
// 			add_token(corewar, &i);
// 	}
// 	define_labels(corewar);
// //	while (TOKEN)
// //	{
// //		printf("%p\n", TOKEN);
// //		TOKEN = TOKEN->next;
// //	}
// }

void			parse(t_cw *corewar)
{
	int		i;
	t_parse	parser;

	i = 0;
	init_parser(&parser);
	first_pars_parse(corewar, &parser, &i);
}

void			init_parser(t_parse *parser)
{
	parser->quotes = 0;
	parser->first_dot = 0;

}

void			first_pars_parse(t_cw *corewar, t_parse *parser, int *i)
{
	while (corewar->line[(*i)])
	{
		if (ft_isspace(corewar->line[(*i)] || corewar->line[(*i)] == ';'
		|| corewar->line[(*i)] == '#'))
			skip_spaces(corewar, i);
		else if (!ft_isspace(corewar->line[(*i)]) && parser->first_dot == 0)
			command(corewar, parser, i);
		(*i)++;
	}
}

void			command(t_cw *corewar, t_parse *parser, int *i)
{
	if (corewar->line[(*i)] != '.')
	{
		fill_commands(corewar, parser, i);
	}
}

void			fill_commands(t_cw *corewar, t_parse *parser, int *i)
{
	char		*line;

	line = ft_strnew(0);
	int j = 0;
	parser->first_dot = 1;
	while (corewar->line[(*i)])
	{
		if (corewar->line[(*i)] == '"' || corewar->line[(*i)] == '\0' ||
			ft_isspace(corewar->line[(*i)]))
			break ;
		ft_join_char_free(&line, corewar->line[(*i)]);
		printf("%s\n", line);

	}
}
