/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:43:57 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/10 19:02:49 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			errors_out(t_cw *corewar, int flag)
{
	if (flag == LEXICAL)
		ft_printf("Lexical error at [%d:%d]\n", corewar->eline, corewar->esym);
	else if (flag == NAME_ERROR)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
COMMAND_NAME \".name\"\n", corewar->eline, corewar->esym);
	else if (flag == COMMENT_ERROR)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
COMMAND_COMMENT \".comment\"\n", corewar->eline, corewar->esym);
	else if (flag == END_LINE_ERROR)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
ENDLINE\n", corewar->eline, corewar->esym);
	else if (flag == SEPARATOR_ERROR)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
SEPARATOR \",\"\n", corewar->eline, corewar->esym);
	else if (flag == 406)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
%s\n", corewar->eline, corewar->esym - ft_strlen(corewar->lastarg)
		, corewar->lastarg);
	else if (flag == ARG_NUM_ERROR)
		ft_printf("Invalid parameter count for instruction %s\n",
			corewar->lastinstr);
	exit(0);
}

void			error_vars(t_cw *corewar, char *str, int flag)
{
	if (flag == LABEL)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
LABEL \"%s\"\n", corewar->eline, corewar->esym, str);
	else if (flag == INSTRUCTION)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
INSTRUCTION \"%s\"\n", corewar->eline, corewar->esym, str);
	exit(0);
}

void			ft_errors(t_cw *corewar)
{
	t_ls		*tmp;

	tmp = corewar->tokens;
	while (tmp->next)
		tmp = tmp->next;
	empty_separator(corewar, tmp);
}

void			empty_separator(t_cw *corewar, t_ls *tmp)
{
	if (tmp->label == REGISTER)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] REGISTER \"%s\"\n",
		corewar->eline, corewar->esym - ft_strlen(tmp->token), tmp->token);
	else if (tmp->label == DIRECT)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] DIRECT \"%s\"\n",
		corewar->eline, corewar->esym - ft_strlen(tmp->token), tmp->token);
	else if (tmp->label == DIRECT_LABEL)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] DIRECT_LABEL \
\"%s\"\n", corewar->eline, corewar->esym - ft_strlen(tmp->token), tmp->token);
	else if (tmp->label == INDIRECTION)
		ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] INDIRECT \"%s\"\n",
		corewar->eline, corewar->esym - ft_strlen(tmp->token), tmp->token);
	exit(0);
}

void			check_eof(t_cw *corewar)
{
	int			len;

	len = ft_strlen(corewar->line);
	while (ft_isspace(corewar->line[--len]))
		if (corewar->line[len] == '\n')
			return ;
	ft_printf("Syntax error - unexpected end of input \
(Perhaps you forgot to end with a newline ?)\n");
	exit(0);
}
