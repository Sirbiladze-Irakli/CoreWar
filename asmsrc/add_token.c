/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:11:08 by jormond-          #+#    #+#             */
/*   Updated: 2019/12/12 15:11:12 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            add_token(t_cw *corewar, int *i)
{
    int         j;
    t_ls        *tmp;

    j = -1;
    tmp = add_node(corewar);
	while (!(separators(corewar->line[(*i)])) && !(ft_isspace(corewar->line[(*i)])))
	{
		tmp->token[++j] = corewar->line[(*i)++];
		corewar->esym++;
	}
	(*i)++;
}

void            define_labels(t_cw *corewar)
{
	t_ls        *tmp;

	tmp = TOKEN;
	while (tmp)
	{
		if (COUNTER != 0)
		{
//			if (corewar->typecode != 0)
//				corewar->res += corewar->typecode--;
			evaluate_instruction(corewar, tmp->token);
			tmp->label = INSTRUCTION;
			COUNTER--;
		}
		else if (tmp->label == 0 && COUNTER == 0)
			fill_label(corewar, tmp);
		tmp = tmp->next;
	}
}

void            fill_label(t_cw *corewar, t_ls *tmp)
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
		fill_label2(corewar, tmp);
	how_many_args(corewar, tmp);
	corewar->dir = dir_size(tmp);
//	corewar->typecode = codetype(tmp);
	corewar->res++;
}

void            fill_label2(t_cw *corewar, t_ls *tmp)
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

void            how_many_args(t_cw *corewar, t_ls *tmp)
{
	if (tmp->label == LIVE || tmp->label == ZJMP || tmp->label == FORK
	|| tmp->label == LFORK || tmp->label == AFF)
		COUNTER = 1;
	else if (tmp->label == LD || tmp->label == ST || tmp->label == LLD)
		COUNTER = 2;
	else if (tmp->label == ADD || tmp->label == SUB || tmp->label == AND
	|| tmp->label == OR || tmp->label == XOR || tmp->label == LDI ||
	tmp->label == STI || tmp->label == LLDI)
		COUNTER = 3;

}