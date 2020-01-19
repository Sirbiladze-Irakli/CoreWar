/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:57:36 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/18 14:35:54 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            read_name(t_cw *corewar)
{
	int		i;
	int		quotes;

	i = -1;
	quotes = 0;
	corewar->name++;
	while (corewar->line[corewar->esym++])
		if (corewar->line[corewar->esym] == '"')
			break ;
	quotes++;
	while(corewar->line[++corewar->esym])
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

int             codetype(t_ls *tmp)
{
	if (tmp->label == LIVE || tmp->label == ZJMP || tmp->label == FORK
	|| tmp->label == LFORK)
		return(0);
	else
		return(1);
}

void            count_args(t_cw *corewar, t_ls *tmp)
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
