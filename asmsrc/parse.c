/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:02:16 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/25 19:18:34 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			parse(t_cw *corewar)
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
		add_token(corewar, &i);
	}
}

void			add_token(t_cw *corewar, int *i)
{
	int		j;

	j = -1;
	// if (corewar->line[(*i)] == '"')
	// {
	// 	add_node(corewar);
	// 	while (corewar->line[++(*i)])
	// 	{
	// 		if (corewar->line[(*i)] == '"')
	// 		{
	// 			(*i)++;
	// 			return ;
	// 		}
	// 		TOKEN->token[++j] = corewar->line[(*i)];
	// 	}
	// }
	add_node(corewar);
	while (corewar->line[(*i)] && !(ft_isspace(corewar->line[(*i)])))
	{
		// if (corewar->line[(*i)])
		// 	return ;
		// printf("%p\n", TOKEN);
		TOKEN->token[++j] = corewar->line[(*i)];

		(*i)++;
		printf("%c\n", TOKEN->token[j]);
	}
	(*i)++;
}
