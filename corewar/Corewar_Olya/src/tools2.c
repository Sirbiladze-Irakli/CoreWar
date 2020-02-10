/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:59:54 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 18:23:58 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int			ft_record_from_arena(int d, t_corewar *corewar)
{
	int		zn;

	zn = ((corewar->arena[ft_limit(d)]) << 24) \
	| ((corewar->arena[ft_limit(d + 1)]) << 16)
	| ((corewar->arena[ft_limit(d + 2)]) << 8)
	| (corewar->arena[ft_limit(d + 3)]);
	return (zn);
}

void		ft_record_to_arena(t_corewar *corewar, int c, int d)
{
	corewar->arena[ft_limit(c)] = (d & 0xff000000) >> 24;
	corewar->arena[ft_limit(c + 1)] = (d & 0x00ff0000) >> 16;
	corewar->arena[ft_limit(c + 2)] = (d & 0x0000ff00) >> 8;
	corewar->arena[ft_limit(c + 3)] = d & 0x000000ff;
}

void		ft_what_arguments(int *d, t_carriage *carriage, \
t_corewar *corewar, int c)
{
	int		i;
	int		point;

	i = -1;
	point = corewar->arena[ft_limit(carriage->pc + 1)];
	while (++i < c)
		d[i] = ft_argument(point, carriage, corewar, i);
}

void		ft_v30(t_corewar *corewar, t_carriage *carriage, int max)
{
	int		i;

	i = -1;
	ft_printf("ADV %i (%#.4x -> %#.4x)", max, carriage->pc, carriage->pc + max);
	while (++i < max)
		ft_printf(" %.2x", corewar->arena[ft_limit(carriage->pc + i)]);
	ft_printf(" \n");
}

int			ft_check_reg(int arg, int regs, int *d)
{
	if ((regs & 4) == 4 && (arg & 192) == 64 && (d[0] < 0 \
	|| d[0] >= REG_NUMBER))
		return (1);
	if ((regs & 2) == 2 && (arg & 48) == 16 && (d[1] < 0 || d[1] >= REG_NUMBER))
		return (1);
	if ((regs & 1) == 1 && (arg & 12) == 4 && (d[2] < 0 || d[2] >= REG_NUMBER))
		return (1);
	return (0);
}
