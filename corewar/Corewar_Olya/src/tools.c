/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:50:19 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 18:23:50 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_new_car(t_carriage ***carriage, t_corewar *corewar, int d, int c)
{
	int		r;

	(*CR)[c]->id = ++(corewar->plus_id);
	(*CR)[c]->carry = (*CR)[CAR + 1]->carry;
	(*CR)[c]->op_code = 0;
	(*CR)[c]->cyc_live = (*CR)[CAR + 1]->cyc_live;
	(*CR)[c]->pc = d;
	(*CR)[c]->arg_types = d + 1;
	(*CR)[c]->byte_jump = 1;
	(*CR)[c]->registrs[0] = (*CR)[CAR + 1]->registrs[0];
	(*CR)[c]->registrs[REG_NUMBER] = (*CR)[CAR + 1]->registrs[REG_NUMBER];
	(*CR)[c]->cyc_to_op = 0;
	(*CR)[c]->move = 1;
	r = 0;
	while (++r < REG_NUMBER)
		(*CR)[c]->registrs[r] = (*CR)[CAR + 1]->registrs[r];
}

void		ft_copy_car(t_carriage ***carriage, t_corewar *corewar, int d)
{
	int		c;

	c = COL_CAR - 1;
	if (CAR_MAS == COL_CAR)
	{
		CAR_MAS *= 2;
		if (!((*carriage) = (t_carriage **)realloc(*carriage, \
		sizeof(t_carriage *) * CAR_MAS)))
			exit(0);
		while (++c < CAR_MAS)
		{
			if (!((*carriage)[c] = (t_carriage *)malloc(sizeof(t_carriage))))
				exit(0);
			ft_create_new_car((*carriage)[c]);
		}
	}
	c = COL_CAR + 1;
	while (--c)
		ft_move_car((*carriage)[c], (*carriage)[c - 1]);
	ft_new_car(carriage, corewar, d, c);
}

int			ft_limit(int d)
{
	if (d >= MEM_SIZE)
		d = (d % MEM_SIZE);
	else if (d < 0)
		d = MEM_SIZE + d % MEM_SIZE;
	return (d);
}

void		ft_reg_value(int *d, int regs, int ar_types, t_carriage *carriage)
{
	if ((regs & 4) == 4 && (ar_types & 192) == 64)
		d[0] = carriage->registrs[d[0]];
	if ((regs & 2) == 2 && (ar_types & 48) == 16)
		d[1] = carriage->registrs[d[1]];
	if ((regs & 1) == 1 && (ar_types & 12) == 4)
		d[2] = carriage->registrs[d[2]];
}

void		ft_carry(t_carriage *carriage, int i)
{
	if (carriage->registrs[i] == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
