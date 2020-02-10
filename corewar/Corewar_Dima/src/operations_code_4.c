/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_code_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:04:48 by cdubuque          #+#    #+#             */
/*   Updated: 2020/01/30 13:25:01 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		ft_ind(t_carriage *carriage, t_corewar *corewar)
{
	short			zn;

	ft_record_short(corewar, carriage, &zn);
	if (carriage->op_code != 13 && carriage->op_code != 3)
		zn %= IDX_MOD;
	carriage->move += 2;
	return (zn);
}

int		ft_dir(t_carriage *carriage, t_corewar *corewar)
{
	int		d;
	short	d1;

	d = 0;
	d1 = 0;
	if (carriage->op_code > 8 && carriage->op_code < 16 \
	&& carriage->op_code != 13)
	{
		ft_record_short(corewar, carriage, &d1);
		carriage->move += 2;
		return (d1);
	}
	else
	{
		d = ft_record_from_arena(carriage->PC + carriage->move, corewar);
		carriage->move += 4;
		return (d);
	}
	return (0);
}

int		ft_reg(t_carriage *carriage, t_corewar *corewar)
{
	int		d;

	d = *(corewar->arena + ft_limit(carriage->PC + carriage->move)) & 255;
	carriage->move++;
	return (d - 1);
}

int		ft_op_code(int par, int i)
{
	int		d;

	d = 0;
	if (i == 0)
	{
		d = par & 192;
		d = d >> 6;
	}
	else if (i == 1)
	{
		d = par & 48;
		d = d >> 4;
	}
	else
	{
		d = par & 12;
		d = d >> 2;
	}
	return (d);
}

int		ft_argument(int par, t_carriage *carriage, t_corewar *corewar, int i)
{
	int		d;

	d = ft_op_code(par, i);
	if (i == 0)
		carriage->move += 1;
	if (d == 1)
		d = ft_reg(carriage, corewar);
	else if (d == 2)
		d = ft_dir(carriage, corewar);
	else
		d = ft_ind(carriage, corewar);
	return (d);
}
