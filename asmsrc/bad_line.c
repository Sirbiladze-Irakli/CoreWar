/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:15:30 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/24 17:36:11 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			bad_line(t_cw *corewar, t_parse *parser, int *i)
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
		ErrorOut(corewar, parser, NAME_ERROR);
	if (!ft_strcmp(str, ".comment"))
		ErrorOut(corewar, parser, COMMENT_ERROR);
	else
		ErrorOut(corewar, parser, LEXICAL);
	free(str);
}

void			before_new_line(t_cw *corewar, t_parse *parser, int *i)
{
	char		*str;
	char		*tmp;
	int			flag;
	
	flag = 0;
	str = ft_strnew(1);
	if (corewar->line[++(*i)] == '\n')
		new_line(corewar);
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
	check_str(corewar, parser, str);
	free(str);
}

void			check_str(t_cw *corewar, t_parse *parser, char *str)
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
