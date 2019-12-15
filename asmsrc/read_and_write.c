/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 13:57:36 by jormond-          #+#    #+#             */
/*   Updated: 2019/12/11 16:10:08 by jormond-         ###   ########.fr       */
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
	if (tmp->label == 0x01 || tmp->label == 0x09 || tmp->label == 0x0c
	|| tmp->label == 0x0f)
		return(0);
	else
		return(1);
}

void            count_args(t_cw *corewar, t_ls *tmp)
{
	ITER = 0;
	how_many_args(corewar, tmp);
	corewar->dir = dir_size(tmp);
	corewar->typecode = codetype(tmp);
	corewar->res++;
}
