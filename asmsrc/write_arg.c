/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:04:15 by jormond-          #+#    #+#             */
/*   Updated: 2019/12/16 12:04:23 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            write_arg(t_cw *corewar, int out, t_ls *tmp)
{
	t_ls        *list;
	int         res;
	int         i;
	char        c;

	i = 0;
	res = 0;
	corewar->iter = 0;
	list = tmp;
	printf("%d curpos\n", tmp->curpos);
	while (corewar->counter--)
	{
		tmp = tmp->next;
		if (corewar->iter == 0 || corewar->iter == 1)
			first_two_args(corewar, out, tmp);
//		else if (ITER == 2)
//			third_arg(corewar, out, tmp);
		corewar->iter++;
	}
	if (tmp->token[i] == 'r')
		while (tmp->token[++i] >= '0' && tmp->token[i] <= '9')
			res = res * 10 + (tmp->token[i] - '0');
	c = res;
	write(out, &c, 1);
	corewar->skip = list->instrbytes;
}

void            first_two_args(t_cw *corewar, int out, t_ls *tmp)
{
	int         i;
	char        r;
	char        ind[IND_SIZE];

	i = 0;
	corewar->res = 0;
	if (tmp->token[i] == 'r')
	{
		while (tmp->token[++i] >= '0' && tmp->token[i] <= '9')
			corewar->res = corewar->res * 10 + (tmp->token[i] - '0');
		r = corewar->res;
		write(out, &r, REG_SIZE);
	}
	else if (tmp->token[i] >= '0' && tmp->token[i] <= '9')
	{
		while (tmp->token[++i] >= '0' && tmp->token[i] <= '9')
			corewar->res = corewar->res * 10 + (tmp->token[i] - '0');
		ind[1] = corewar->res & 255;
		ind[0] = (corewar->res & 65280) >> 8;
		write (out, ind, IND_SIZE);
	}
	else if (tmp->token[i] == '%')
		write_dir(corewar, out, tmp);
}

void            write_dir(t_cw *corewar, int out, t_ls *tmp)
{
	char        label[48];
	int         i;
	int         j;
	int         res;

	j = 0;
	i = 1;
	res = 0;
	ft_bzero(label, 48);
	if (tmp->token[1] == ':')
	{
		while (tmp->token[++i])
			label[j++] = tmp->token[i];
		label[j++] = ':';
		jump_lenght(corewar, tmp, label, out);
	}
	else if (tmp->token[i] >= 0 && tmp->token[i] <= 9)
	{
		while (tmp->token[i++])
			res = res * 10 + (tmp->token[i] - '0');

	}
}

void            jump_lenght(t_cw *corewar, t_ls *tmp, char *label, int out)
{
	t_ls        *list;
	char        wr[corewar->dir];
	int         i;
	int         len;
	uint8_t     shift;

	i = corewar->dir;
	list = corewar->tokens;
	shift = 0;
	while (list)
	{
		if (list->label > 0 && list->label < 17)
			corewar->skip = list->curpos;
		if (!(ft_strcmp(list->token, label)))
			break ;
		list = list->next;
	}
	len = corewar->skip - tmp->curpos;
	while (i--)
	{
		wr[i] = (wr[i] | len) >> shift;
		shift += 8;
	}
	write(out, wr, corewar->dir);
}