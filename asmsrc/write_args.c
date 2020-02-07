
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:04:15 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/20 17:39:18 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_reg(t_cw *corewar, int out, t_ls *list)
{
	int			i;
	int			res;
	char		reg;

	i = 0;
	res = 0;
	while (list->token[++i])
			res = res * 10 + (list->token[i] - '0');
		reg = res;
	write(out, &reg, 1);
}

void			write_direct(t_cw *corewar, int out, t_ls *list)
{
	int			res;
	int			i;
	int			shift;
	char		dir[corewar->dir];

	i = 0;
	res = 0;
	shift = 0;
	ft_bzero(dir, corewar->dir);
	while (list->token[++i])
		res = res * 10 + (list->token[i] - '0');
	i = corewar->dir;
	while (i--)
	{
		dir[i] = (dir[i] |= res) >> shift;
		shift += 8;
	}
	write(out, dir, corewar->dir);
}

void			write_ind(t_cw *corewar, int out, t_ls *list)
{
	int			i;
	int			res;
	char		ind[IND_SIZE];

	i = -1;
	res = 0;
	ft_bzero(ind, IND_SIZE);
	while (list->token[++i])
		res = res * 10 + (list->token[i] - '0');
	ind[1] |= res;
	ind[0] |= res >> 8;
	write(out, ind, IND_SIZE);
}

void			write_dir_lab(t_cw *corewar, int out, t_ls *list)
{
	t_ls		*tmp;
	int			res;
	int			i;
	uint8_t		shift;
	char		dir[corewar->dir];

	ft_bzero(dir, corewar->dir);
	tmp = find_label(corewar, list, 2);
	res = calc_range(list, tmp);
	i = corewar->dir;
	shift = 0;
	while (i--)
	{
		dir[i] |= res >> shift;
		shift += 8;
	}
	write(out, dir, corewar->dir);
}

void			write_ind_lab(t_cw *corewar, int out, t_ls *list)
{
	t_ls		*tmp;
	int			res;
	char		ind[IND_SIZE];

	tmp = find_label(corewar, list, 1);
	res = calc_range(list, tmp);
	ind[1] = res & 255;
	ind[0] = (res & 65280) >> 8;
	write(out, ind, IND_SIZE);
}

void            write_args(t_cw *corewar, int out, t_ls *tmp)
{
	int         res;
	int         i;
	char        c;

	i = 0;
	res = 0;
	corewar->iter = 0;
	corewar->tokens = tmp;
	while (corewar->counter--)
	{
		tmp = tmp->next;
		if (corewar->iter == 0 || corewar->iter == 1)
			first_two_args(corewar, out, tmp);
		else if (corewar->iter == 2)
			third_arg(corewar, out, tmp);
		corewar->iter++;
	}
	corewar->skip = corewar->tokens->instrbytes;
}

void            first_two_args(t_cw *corewar, int out, t_ls *tmp)
{
	int         i;
	int         res;
	char        r;
	char        ind[IND_SIZE];

	i = 0;
	res = 0;
	if (tmp->token[i] == 'r')
	{
		while (tmp->token[++i] >= '0' && tmp->token[i] <= '9')
			res = res * 10 + (tmp->token[i] - '0');
		r = res;
		write(out, &r, 1);
	}
	else if (tmp->token[i] >= '0' && tmp->token[i] <= '9')
	{
		while (tmp->token[++i] >= '0' && tmp->token[i] <= '9')
			corewar->res = corewar->res * 10 + (tmp->token[i] - '0');
		ind[1] = res & 255;
		ind[0] = (res & 65280) >> 8;
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
	if (tmp->token[i] == ':')
	{
		while (tmp->token[++i])
			label[j++] = tmp->token[i];
		label[j++] = ':';
		jump_lenght(corewar, tmp, label, out);
	}
	else
	{
		while (tmp->token[i])
			res = res * 10 + (tmp->token[i++] - '0');
		write_in_file(corewar, res, out);
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
	list = corewar->startnode;
	shift = 0;
	ft_bzero(wr, corewar->dir);
	while (list) {
		if (list->label > 0 && list->label < 17)
			corewar->skip = list->curpos;
		if (!(ft_strcmp(list->token, label)))
			break ;
		list = list->next;
	}
	corewar->skip = list->next->curpos;
	len = corewar->skip - corewar->tokens->curpos;
	while (i--)
	{
		wr[i] = (wr[i] | len) >> shift;
		shift += 8;
	}
	write(out, wr, corewar->dir);
}