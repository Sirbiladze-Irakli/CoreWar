/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:11:08 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/09 17:12:45 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			add_token(t_cw *corewar, int *i)
{
	int			j;
	t_ls		*tmp;

	j = -1;
	tmp = add_node(corewar);
	while (!(separators(corewar->line[(*i)])) &&
		!(ft_isspace(corewar->line[(*i)])))
	{
		tmp->token[++j] = corewar->line[(*i)++];
		corewar->esym++;
	}
	(*i)++;
}

void			define_labels(t_cw *corewar)
{
	t_ls		*tmp;

	tmp = corewar->tokens;
	while (tmp)
	{
		if (corewar->counter != 0)
		{
			if (corewar->typecode != 0)
				corewar->res += corewar->typecode--;
			evaluate_instruction(corewar, tmp->token);
			tmp->label = INSTRUCTION;
			corewar->counter--;
		}
		else if (tmp->label == 0 && corewar->counter == 0)
			fill_label(tmp);
		if (tmp->label > 0 && tmp->label < 17)
			count_args(corewar, tmp);
		tmp = tmp->next;
	}
}

void			fill_label(t_ls *tmp)
{
	if (tmp->token[ft_strlen(tmp->token) - 1] == ':')
		tmp->label = LABEL;
	else if (!(ft_strcmp(tmp->token, "live")))
		tmp->label = LIVE;
	else if (!(ft_strcmp(tmp->token, "ld")))
		tmp->label = LD;
	else if (!(ft_strcmp(tmp->token, "st")))
		tmp->label = ST;
	else if (!(ft_strcmp(tmp->token, "add")))
		tmp->label = ADD;
	else if (!(ft_strcmp(tmp->token, "sub")))
		tmp->label = SUB;
	else if (!(ft_strcmp(tmp->token, "and")))
		tmp->label = AND;
	else if (!(ft_strcmp(tmp->token, "or")))
		tmp->label = OR;
	else
		fill_label2(tmp);
}

void			fill_label2(t_ls *tmp)
{
	if (!(ft_strcmp(tmp->token, "fork")))
		tmp->label = FORK;
	else if (!(ft_strcmp(tmp->token, "lld")))
		tmp->label = LLD;
	else if (!(ft_strcmp(tmp->token, "lldi")))
		tmp->label = LLDI;
	else if (!(ft_strcmp(tmp->token, "lfork")))
		tmp->label = LFORK;
	else if (!(ft_strcmp(tmp->token, "aff")))
		tmp->label = AFF;
	else if (!(ft_strcmp(tmp->token, "ldi")))
		tmp->label = LDI;
	else if (!(ft_strcmp(tmp->token, "sti")))
		tmp->label = STI;
	else if (!(ft_strcmp(tmp->token, "xor")))
		tmp->label = XOR;
	else if (!(ft_strcmp(tmp->token, "zjmp")))
		tmp->label = ZJMP;
}

void			how_many_args(t_cw *corewar, t_ls *tmp)
{
	if (tmp->label == LIVE || tmp->label == ZJMP || tmp->label == FORK
	|| tmp->label == LFORK || tmp->label == AFF)
		corewar->counter = 1;
	else if (tmp->label == LD || tmp->label == ST || tmp->label == LLD)
		corewar->counter = 2;
	else if (tmp->label == ADD || tmp->label == SUB || tmp->label == AND
	|| tmp->label == OR || tmp->label == XOR || tmp->label == LDI ||
	tmp->label == STI || tmp->label == LLDI)
		corewar->counter = 3;
}
