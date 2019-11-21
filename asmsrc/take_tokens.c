/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:25:36 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/21 20:40:49 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            take_tokens(t_cw *corewar)
{
	while (get_next_line(corewar->in, &corewar->line))
	{
		parse_tokens(corewar);
		free(corewar->line);
	}
	// printf("%s\n", corewar->line);
	return ;
}

void            parse_tokens(t_cw *corewar)
{
	corewar->eline++;

	printf("%s\n", corewar->line);
	if (corewar->name == 0 || corewar->comment == 0)
		name_and_comment(corewar);
}

void            name_and_comment(t_cw *corewar)
{
	if (corewar->name == 0)
	{
		if (ft_strstr(corewar->line, ".name"))
		{
			corewar->name++;
			name_and_comment_reader(corewar, 1);
		}
	}
	else if (corewar->name == 0)
	{
		if (ft_strstr(corewar->line, ".comment"))
		{
			corewar->comment++;
			name_and_comment_reader(corewar, 2);
		}
	}
	corewar->esym = 0;
	if (corewar->name > 1 || corewar->comment > 1)
		error_out(corewar, 1, "\0");
}
