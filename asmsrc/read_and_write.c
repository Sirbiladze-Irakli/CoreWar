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

void            fill_commands(t_cw *corewar, int out)
{
	t_ls    *list;
	char    c;

	list = TOKEN;
	while (list)
	{
		if (list->label > 0 && list->label < 17)
		{
			c = list->label;
			write(out, &c, 1);
		}
		list = list->next;
	}
}

//int             codetype(t_ls *tmp)
//{
//	if (tmp->label == 0x01 || tmp->label == 0x09 || tmp->label == 0x0c
//	|| tmp->label == 0x0f)
//		return(0);
//	else
//		return(1);
//}