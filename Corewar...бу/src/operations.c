/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:59:24 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/16 19:12:01 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_operations_2(t_carriage ***carriege, t_corewar *corewar, int i)
{
	if ((*carriege)[i]->op_code == 11)
		ft_sti(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 12)
		ft_fork(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 13)
		ft_lld(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 14)
		ft_lldi(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 15)
		ft_lfork(&carriege, corewar, i);
	else
		ft_aff(&carriege, corewar, i);
}

void		ft_operations(t_carriage ***carriege, t_corewar *corewar, int i)
{
	if ((*carriege)[i]->op_code == 1)
		ft_live(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 2)
		ft_ld(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 3)
		ft_st(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 4)
		ft_add(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 5)
		ft_sub(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 6)
		ft_and(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 7)
		ft_or(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 8)
		ft_xor(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 9)
		ft_zjmp(&carriege, corewar, i);
	else if ((*carriege)[i]->op_code == 10)
		ft_ldi(&carriege, corewar, i);
	else 
		ft_operations_2(&carriege, corewar, i);
}