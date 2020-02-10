/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:59:24 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/05 19:51:07 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_wrong_ar_types(t_carriage *carriage, t_corewar *corewar, \
int ar_types, int i)
{
	int		d;
	int		n;

	d = -1;
	n = 0;
	CR->move = 1;
	while (++d < i)
	{
		n = ar_types & 192;
		n = n >> 6;
		if (n == 1)
			CR->move += 1;
		else if (n == 2)
			CR->move += op_tab[CR->op_code - 1].dir;
		else if (n == 3)
			CR->move += 2;
		ar_types = ar_types << 2;
	}
	if (CW->v30 == 1)
		ft_v30(CW, CR, CR->move + 1);
	CR->PC = ft_limit(CR->PC + CR->move + 1);
}

void		ft_operations(t_carriage ***carriage, t_corewar *corewar)
{
	if ((*carriage)[CAR]->op_code == 1)
		ft_live((*carriage)[CAR], corewar);
	else if ((*carriage)[CAR]->op_code == 2 || (*carriage)[CAR]->op_code == 13)
		ft_ld_and_lld((*carriage)[CAR], corewar);
	else if ((*carriage)[CAR]->op_code == 3)
		ft_st((*carriage)[CAR], corewar);
	else if ((*carriage)[CAR]->op_code == 4 || (*carriage)[CAR]->op_code == 5)
		ft_add_and_sub((*carriage)[CAR], corewar);
	else if ((*carriage)[CAR]->op_code > 5 && (*carriage)[CAR]->op_code < 9)
		ft_and_or_xor((*carriage)[CAR], corewar);
	else if ((*carriage)[CAR]->op_code == 9)
		ft_zjmp((*carriage)[CAR], corewar);
	else if ((*carriage)[CAR]->op_code == 10 || (*carriage)[CAR]->op_code == 14)
		ft_ldi_and_lldi((*carriage)[CAR], corewar);
	else if ((*carriage)[CAR]->op_code == 11)
		ft_sti((*carriage)[CAR], corewar);
	else if ((*carriage)[CAR]->op_code == 12 || (*carriage)[CAR]->op_code == 15)
		ft_fork_and_lfork(carriage, corewar);
	else if ((*carriage)[CAR]->op_code == 16)
		ft_aff((*carriage)[CAR], corewar);
	(*carriage)[CAR]->arg_types = ft_limit((*carriage)[CAR]->PC + 1);
	(*carriage)[CAR]->cyc_to_op = 0;
	(*carriage)[CAR]->move = 1;
}
