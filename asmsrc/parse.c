/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:02:16 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/22 18:26:17 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			parse(t_cw *corewar)   // seg fault. repair it !!!!!!!!!!!!
{
	int		i;

	i = 0;
	while (corewar->line[i])
	{
		if (ft_isspace(corewar->line[i]))
		{
			if (corewar->line[i] == '\n')
				corewar->esym = 0;
			i++;
		}
		while (!ft_isspace(corewar->line[i]))
			add_token(corewar, &i);
	}
}

void			add_token(t_cw *corewar, int *i)
{
	int		j;
	t_ls	*tmp;

	j = -1;
	if (corewar->line[(*i)] == '"')
	{
		prepare_node(corewar, &tmp);
		while (corewar->line[++(*i)])
		{
			if (corewar->line[(*i)] == '"')
			{
				(*i)++;
				return ;
			}
			TOKEN->token[++j] = corewar->line[(*i)];
		}
	}
	prepare_node(corewar, &tmp);
	while (corewar->line[(*i)])
	{
		if (corewar->line[(*i)])
			return ;
		TOKEN->token[++j] = corewar->line[(*i)];
	}
}
