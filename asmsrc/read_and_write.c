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
	// printf("%s name\n", corewar->inname);
	if (quotes != 2)
		errors(corewar, 2, 0);
	if (corewar->line[++corewar->esym] != '\0')
		errors(corewar, 2, 0);
}
