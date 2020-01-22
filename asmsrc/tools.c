/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:51:18 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/20 18:39:12 by jormond-         ###   ########.fr       */
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
	printf("%d dirsize\n", corewar->dir);
	if (ft_strchr(token, '%'))
	{
		corewar->res += corewar->dir;
		corewar->instruct->instrbytes += corewar->dir;
		return ;
	}
	else if (ft_strchr(token, 'r'))
	{
		corewar->res += 1;
		corewar->instruct->instrbytes += 1;
		return ;
	}
	corewar->res += IND_SIZE;
	corewar->instruct->instrbytes += IND_SIZE;
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
	if (corewar->line[(*i)] == ';' || corewar->line[(*i)] == '#')
			while (corewar->line[(*i)] && corewar->line[(*i)] != '\n')
				(*i)++;
	while (ft_isspace(corewar->line[(*i)]))
	{
		corewar->esym++;
		if (corewar->line[(*i)] == '\n')
			new_line(corewar);
		(*i)++;
	}
}

int				separators(char c)
{
	return ((c == '"' || c == ',' || c == ';' || c == '#'));
}

void			new_line(t_cw *corewar)
{
	corewar->esym = 1;
	corewar->eline++;
}
