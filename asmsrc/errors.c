/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:19:34 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/09 16:57:34 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
