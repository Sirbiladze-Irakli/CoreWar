/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:02:16 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/26 17:58:05 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			parse(t_cw *corewar)
{
	int		i;

	i = 0;
	while (corewar->line[i])
	{
		// printf("\n|%c|\n", corewar->line[i]);
		if (ft_isspace(corewar->line[i]))
		{
			if (corewar->line[i] == '\n')
			{
				corewar->esym = 1;
				corewar->eline++;
			}
			i++;
		}
		add_token(corewar, &i);
	}
}

void			add_token(t_cw *corewar, int *i)
{
	int		j;

	j = -1;
	add_node(corewar);
	if (corewar->line[(*i)] == '"')
		token_in_quotes(corewar, i);
	while (corewar->line[(*i)] && !(ft_isspace(corewar->line[(*i)])))
	{
		// if (corewar->name == 1 || corewar->comment == 1)
		// 	fill_name_and_comment(corewar, i);
		TOKEN->token[++j] = corewar->line[(*i)];
		corewar->esym++;
		(*i)++;
		printf("%c\n", TOKEN->token[j]);
		if (corewar->line[(*i)] == '"')
			break ;
	}
	// printf("|%s|\n", TOKEN->token);
	if (ft_strstr(TOKEN->token, ".name") && corewar->name != 1000)
		corewar->name++;
	else if (ft_strstr(TOKEN->token, ".comment") && corewar->comment != 1000)
		corewar->comment++;
	if (corewar->name > 1 || corewar->comment > 1)
		errors(corewar, 1);
	printf("-------------\n");
}
