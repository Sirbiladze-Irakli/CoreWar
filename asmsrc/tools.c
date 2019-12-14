/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:51:18 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/29 17:16:14 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

void            evaluate_instruction(t_cw *corewar, char *token)
{
	if (ft_strchr(token, '%'))
	{
		corewar->res += corewar->dir;
		return ;
	}
	else if (ft_strchr(token, 'r'))
	{
		corewar->res += 1;
		return ;
	}
	else
		corewar->res += 2;
}

int             dir_size(t_ls *tmp)
{
	if (tmp->label == LIVE || tmp->label == LD || tmp->label == ST ||
	tmp->label == ADD || tmp->label == SUB || tmp->label == AND || tmp->label
	== OR || tmp->label == XOR || tmp->label == LLD || tmp->label == AFF)
		return (4);
	else
		return (2);
}

void			skip_spaces(t_cw *corewar, int *i)
{
	while (ft_isspace(corewar->line[(*i)]))
	{
		corewar->esym++;
		if (corewar->line[(*i)] == '\n')
		{
			corewar->esym = 1;
			corewar->eline++;
		}
		(*i)++;
	}
}

int				separators(char c)
{
	return ((c == '"' || c == ',' || c == ';' || c == '#'));
}
