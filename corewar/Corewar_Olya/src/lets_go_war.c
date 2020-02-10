/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_go_war.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 18:30:29 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 18:22:06 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	ft_create_new_car(t_carriage *carriage)
{
	int		r;

	CR->id = 0;
	CR->carry = 0;
	CR->op_code = 0;
	CR->cyc_live = 0;
	CR->pc = 0;
	CR->arg_types = 0;
	CR->byte_jump = 0;
	CR->cyc_to_op = 0;
	CR->move = 0;
	r = -1;
	while (++r < REG_NUMBER)
		CR->registrs[r] = 0;
}

void	ft_kill_car(t_carriage ***carriage, int *i, t_corewar *corewar)
{
	int		c;

	c = *i;
	if (CW->v30 == 1)
		ft_printf("Process %i hasn't lived for %i cycles (CTD %i)\n", \
		(*CR)[c]->id, CW->start_cycles - (*CR)[c]->cyc_live, CW->cycles_to_die);
	if (c != COL_CAR - 1)
	{
		--c;
		while (++c < COL_CAR - 1)
			ft_move_car((*CR)[c], (*CR)[c + 1]);
	}
	COL_CAR--;
	(*i)--;
}

void	ft_verification_go(t_corewar *corewar, t_carriage ***carriage)
{
	int		i;

	i = -1;
	while (++i < COL_CAR)
	{
		if (CW->start_cycles - (*CR)[i]->cyc_live >= CW->cycles_to_die \
		|| CW->cycles_to_die < 0)
			ft_kill_car(CR, &i, CW);
	}
	if (CW->col_check == MAX_CHECKS || CW->col_live >= NBR_LIVE)
	{
		CW->cycles_to_die -= CYCLE_DELTA;
		if (CW->v30 == 1)
			ft_printf("Cycle to die is now %i\n", CW->cycles_to_die);
		CW->col_check = 1;
	}
	else
		CW->col_check++;
	CW->col_live = 0;
	CW->cycle = 0;
}

void	ft_cycle(t_carriage ***carriage, t_corewar *corewar)
{
	if ((*CR)[CAR]->cyc_to_op == 0)
		(*CR)[CAR]->op_code = CW->arena[(*CR)[CAR]->pc];
	if ((*CR)[CAR]->op_code > 0 && (*CR)[CAR]->op_code < 17)
	{
		if ((*CR)[CAR]->cyc_to_op == 0)
			(*CR)[CAR]->cyc_to_op = g_op_tab[(*CR)[CAR]->op_code - 1].cycles;
		if ((*CR)[CAR]->cyc_to_op > 1)
			(*CR)[CAR]->cyc_to_op--;
		else
			ft_operations(CR, CW);
	}
	else
	{
		(*CR)[CAR]->pc = ft_limit((*CR)[CAR]->pc + 1);
		(*CR)[CAR]->arg_types = ft_limit((*CR)[CAR]->pc + 1);
	}
}

void	ft_lets_go_war(t_corewar *corewar, t_carriage ***carriage)
{
	int		i;

	i = -1;
	while (((CW->start_cycles < CW->dump) || CW->dump < 0) && CW->col_car != 0 \
	&& (CW->cycle++ <= CW->cycles_to_die || CW->cycles_to_die < 0))
	{
		CW->start_cycles++;
		if (CW->v30 == 1)
			ft_printf("It is now cycle %i\n", CW->start_cycles);
		while (++CAR < COL_CAR)
			ft_cycle(CR, CW);
		if (CW->cycle == CW->cycles_to_die || CW->cycles_to_die < 0)
			ft_verification_go(CW, CR);
		CAR = -1;
	}
	while (++i < CAR_MAS)
		free((*carriage)[i]);
	free(*carriage);
}
