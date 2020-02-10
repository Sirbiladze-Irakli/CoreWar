/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:04:15 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/09 17:03:41 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_reg(int out, t_ls *list)
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

void			write_dir(t_cw *corewar, int out, t_ls *list)
{
	int			res;
	int			i;
	char		dir[corewar->dir];

	res = 0;
	i = wtf(list);
	ft_bzero(dir, corewar->dir);
	while (list->token[++i])
		res = res * 10 + (list->token[i] - '0');
	if (list->token[1] == '-')
		res *= -1;
	if (corewar->dir == 2)
	{
		dir[1] = res & 255;
		dir[0] = (res & 65280) >> 8;
	}
	else
	{
		dir[3] = res & 255;
		dir[2] = (res & 65280) >> 8;
		dir[1] = (res & 16711680) >> 16;
		dir[0] = (res & 4278190080) >> 24;
	}
	write(out, dir, corewar->dir);
}

void			write_ind(int out, t_ls *list)
{
	int			i;
	int			res;
	char		ind[IND_SIZE];

	res = 0;
	i = wtf(list);
	ft_bzero(ind, IND_SIZE);
	while (list->token[++i])
		res = res * 10 + (list->token[i] - '0');
	if (list->token[0] == '-')
		res *= -1;
	ind[1] = res & 255;
	ind[0] = (res & 65280) >> 8;
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
