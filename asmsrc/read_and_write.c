/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:57:36 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/09 17:00:22 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_ls			*find_label(t_cw *corewar, t_ls *list, int begin)
{
	t_ls		*tmp;

	tmp = corewar->tokens->next->next->next->next;
	while (tmp->head != 1)
	{
		if (tmp->label == LABEL)
			if (!substrncmp(list->token, tmp->token, begin,
			ft_strlen(list->token) - begin))
				break ;
		tmp = tmp->next;
	}
	return (tmp);
}

int				calc_range(t_ls *list, t_ls *tmp)
{
	t_ls		*instr;

	instr = list;
	while (instr->label > 16)
		instr = instr->prev;
	return (tmp->pos - instr->pos);
}

void			read_name(t_cw *corewar)
{
	int			i;
	int			quotes;

	i = -1;
	quotes = 0;
	corewar->name++;
	while (corewar->line[corewar->esym++])
		if (corewar->line[corewar->esym] == '"')
			break ;
	quotes++;
	while (corewar->line[++corewar->esym])
	{
		if (corewar->line[corewar->esym] == '"')
		{
			quotes++;
			break ;
		}
		corewar->inname[++i] = corewar->line[corewar->esym];
	}
	if (quotes != 2)
		errors(corewar, 2, 0);
	if (corewar->line[++corewar->esym] != '\0')
		errors(corewar, 2, 0);
}

int				codetype(t_ls *tmp)
{
	if (tmp->label == LIVE || tmp->label == ZJMP || tmp->label == FORK
	|| tmp->label == LFORK)
		return (0);
	else
		return (1);
}

void			count_args(t_cw *corewar, t_ls *tmp)
{
	corewar->iter = 0;
	how_many_args(corewar, tmp);
	corewar->dir = dir_size(tmp);
	corewar->typecode = codetype(tmp);
	tmp->args = corewar->counter;
	corewar->instruct = tmp;
	tmp->curpos = corewar->res;
	corewar->res++;
}
