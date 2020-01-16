/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:02:16 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/16 16:30:14 by jormond-         ###   ########.fr       */
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
			skip_spaces(corewar, &i);
		else if (corewar->line[i] == '.')
			dot_label(corewar, &i);
		else if (corewar->line[i] == '"')
			token_in_quotes(corewar, &i);
		else if (corewar->line[i] == ';' || corewar->line[i] == '#')
			while (corewar->line[i] && corewar->line[i] != '\n')
				i++;
		else
			add_token(corewar, &i);
	}
	define_labels(corewar);
//	while (TOKEN)
//	{
//		printf("%p\n", TOKEN);
//		TOKEN = TOKEN->next;
//	}
}
