/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_is_who.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:22:00 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/09 18:15:14 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			who_is_who(t_cw *corewar, t_parse *parser, int *i)
{
	char		*str;

	str = ft_strnew(1);
	while (corewar->line[(*i)])
	{
		if (ft_isspace(corewar->line[(*i)]) || separators(corewar->line[(*i)]))
		{
			if (parser->args != 0)
				instr_arg(corewar, parser, str);
			else
			{
				ft_strtrim_free(&str);
				define_str(corewar, parser, str);
			}
			free(str);
			return ;
		}
		ft_join_char_free(&str, corewar->line[(*i)]);
		corewar->esym++;
		(*i)++;
	}
	free(str);
}

void			define_str(t_cw *corewar, t_parse *parser, char *str)
{
	t_ls		*tmp;

	tmp = corewar->tokens;
	if (tab(str))
		process_instr(corewar, parser, str);
	else if (str[ft_strlen(str) - 1] == ':')
	{
		check_label(corewar, str);
		tmp = add_node(corewar);
		tmp->label = LABEL;
		if (!(corewar->labels[parser->j] = (char *)malloc(sizeof(char)
			* ft_strlen(str))))
			output("Can't alloceta a memory");
		ft_bzero(corewar->labels[parser->j], ft_strlen(str));
		ft_strncpy(corewar->labels[parser->j], str, ft_strlen(str) - 1);
		ft_strcpy(tmp->token, str);
		parser->j++;
	}
	else
		ft_errors(corewar);
}

int				tab(char *str)
{
	int			i;

	i = 0;
	while (++i < 17)
		if (!ft_strcmp(op_tab[i].instr, str))
			return (i);
	return (0);
}

void			check_instr(t_cw *corewar, t_parse *parser, int *i)
{
	if (parser->args > 0 && parser->commas == (parser->args * -1)
		&& corewar->line[(*i)] == '\n')
		errors_out(corewar, ARG_NUM_ERROR);
	else if (parser->args > 0 && corewar->line[(*i)] == '\n')
		errors_out(corewar, END_LINE_ERROR);
	else if (parser->args == 0 && parser->commas < 0)
		ft_errors(corewar);
}

void			check_label(t_cw *corewar, char *str)
{
	int			err;
	regex_t		reg;
	regmatch_t	pm;

	err = regcomp(&reg, LABEL_PATTERN, REG_EXTENDED);
	if (regexec(&reg, str, 0, &pm, 0))
	{
		regfree(&reg);
		error_out(corewar, 0);
		exit(0);`
	}
	regfree(&reg);
}
