/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:27:06 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/22 19:09:02 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			compare_val(t_cw *corewar, t_parse *parser, char *line, int *i)
{
	t_ls	*tmp;

	tmp = corewar->tokens;
	if (!ft_strcmp(".comment", line))
	{
		tmp = add_node(corewar);
		parser->comment += 1;
		tmp->label = COMMAND_COMMENT;
		command_val(corewar, tmp, parser, i);
	}
	else if (!ft_strcmp(".name", line))
	{
		tmp = add_node(corewar);
		parser->name += 1;
		tmp->label = COMMAND_NAME;
		command_val(corewar, tmp, parser, i);
	}
	else
		ErrorOut(corewar, parser, LEXICAL);
	// while (corewar->tokens->prev)
	// 	corewar->tokens = corewar->tokens->prev;
}

void			command_val(t_cw *corewar, t_ls *tmp, t_parse *parser, int *i)
{
	t_ls		*val;
	char		*str;

	val = tmp;
	val = add_node(corewar);
	str = ft_strnew(1);
	while (corewar->line[(*i)])
	{
		if (corewar->line[(*i)] == '"' && parser->quotes == 0)
			parser->quotes = 1;
		else if (corewar->line[(*i)] == '"' && parser->quotes == 1)
			break ;
		else if (parser->quotes == 1)
			ft_join_char_free(&str, corewar->line[(*i)]);
		corewar->esym++;
		(*i)++;
	}
	ft_strcpy(val->token, str);
	free(str);
	parser->quotes = 0;
	if (tmp->label == COMMAND_COMMENT)
		val->label = COMMENT;
	else
		val->label = NAME;
}