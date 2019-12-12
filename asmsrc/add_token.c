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
	int         counter;
	t_ls        *tmp;

	tmp = TOKEN;
	counter = 0;
	while (tmp)
	{
		if (tmp->label == 0)
			fill_label(&counter, tmp);
		tmp = tmp->next;
	}
}

void            fill_label(int *counter, t_ls *tmp)
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
	else if (!(ft_strcmp(tmp->token, "xor")))
		tmp->label = XOR;
	else if (!(ft_strcmp(tmp->token, "zjmp")))
		tmp->label = ZJMP;
	else if (!(ft_strcmp(tmp->token, "ldi")))
		tmp->label = LDI;
	else if (!(ft_strcmp(tmp->token, "sti")))
		tmp->label = STI;
	else
		fill_label2(counter, tmp);
	printf("%s\n", tmp->token);
	printf("%d\n", tmp->label);
}

void            fill_label2(int *counter, t_ls *tmp)
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
	(*counter) = how_many_args(tmp);
}

int             how_many_args(t_ls *tmp)
{
	if (tmp->label == LIVE || tmp->label == ZJMP || tmp->label == FORK
	|| tmp->label == LFORK || tmp->label == AFF)
		return (1);
	else if (tmp->label == LD || tmp->label == ST || tmp->label == LLD)
		return (2);
	else if (tmp->label == ADD || tmp->label == SUB || tmp->label == AND
	|| tmp->label == OR || tmp->label == XOR || tmp->label == LDI ||
	tmp->label == STI || tmp->label == LLDI)
		return (3);
}