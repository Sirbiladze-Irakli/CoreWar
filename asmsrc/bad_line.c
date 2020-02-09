/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:15:30 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/09 16:20:39 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			bad_line(t_cw *corewar, int *i)
{
	char		*str;

	str = ft_strnew(1);
	while (corewar->line[(*i)])
	{
		if (corewar->line[(*i)] == ';' || corewar->line[(*i)] == '#'
			|| ft_isspace(corewar->line[(*i)]))
			break ;
		if (corewar->line[(*i)] == '\n')
			new_line(corewar);
		ft_join_char_free(&str, corewar->line[(*i)]);
		(*i)++;
	}
	if (!ft_strcmp(str, ".name"))
		errors_out(corewar, NAME_ERROR);
	if (!ft_strcmp(str, ".comment"))
		errors_out(corewar, COMMENT_ERROR);
	else
		errors_out(corewar, LEXICAL);
	free(str);
}

void			before_new_line(t_cw *corewar, int *i)
{
	char		*str;
	char		*tmp;
	int			flag;

	flag = 0;
	str = ft_strnew(1);
	(*i)++;
	while (corewar->line[(*i)] && corewar->line[(*i)] != '\n')
	{
		if (ft_isspace(corewar->line[(*i)]))
			corewar->esym++;
		ft_join_char_free(&str, corewar->line[(*i)]);
		(*i)++;
	}
	tmp = ft_strtrim(str);
	free(str);
	str = tmp;
	check_str(corewar, str);
	free(str);
}

void			check_str(t_cw *corewar, char *str)
{
	if (str[0] == '%' && str[1] == ':')
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
DIRECT_LABEL \"%s\"\n", corewar->eline, corewar->esym, str);
	else if (ft_strchr(str, '%'))
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
DIRECT \"%s\"\n", corewar->eline, corewar->esym, str);
	else if (ft_strchr(str, ':'))
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
LABEL \"%s\"\n", corewar->eline, corewar->esym, str);
	else if (str[0] == 'r' && (ft_strchr("0123456789", str[1])))
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
DIRECT \"%s\"\n", corewar->eline, corewar->esym, str);
	else if (ft_strcmp(str, ""))
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
INSTRUCTION \"%s\"\n", corewar->eline, corewar->esym, str);
	if (!ft_strcmp(str, ""))
		return ;
	exit(0);
}
