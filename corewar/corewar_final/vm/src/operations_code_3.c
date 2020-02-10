/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_code_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:04:52 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 19:50:41 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_sti(t_carriage *carriage, t_corewar *corewar)
{
	int		d[3];
	int		ad;

	ad = 0;
	ft_what_arguments(d, CR, CW, 3);
	if (!(ft_check_reg(AR_TYPES, 7, d)) && (AR_TYPES & 192) == 64 && \
	(AR_TYPES & 48) != 0 && ((AR_TYPES & 12) == 4 || (AR_TYPES & 12) == 8))
	{
		ft_reg_value(d, 3, AR_TYPES, CR);
		if ((AR_TYPES & 48) == 48)
			d[1] = ft_record_from_arena(CR->pc + d[1], CW);
		ad = CR->pc + (d[1] + d[2]) % IDX_MOD;
		if (CW->v30 == 1)
		{
			ft_printf("P %4i | sti r%i %i %i\n", CR->id, d[0] + 1, d[1], d[2]);
			ft_printf("%20s %i + %i = %i (with pc and mod %i)\n", \
			"| -> store to", d[1], d[2], d[1] + d[2], ad);
		}
		ft_record_to_arena(CW, ad, CR->registrs[d[0]],
		abs(CR->registrs[REG_NUMBER]));
		if (CW->v30 == 1)
			ft_v30(CW, CR, CR->move);
		CR->pc = ft_limit(CR->pc + CR->move);
	}
	else
		ft_wrong_ar_types(carriage, corewar, AR_TYPES, 3);
}

void		ft_fork_and_lfork(t_carriage ***carriage, t_corewar *corewar)
{
	short		d[2];
	int			d2[2];

	d[0] = ft_dir((*CR)[CAR], CW);
	d[1] = d[0];
	if ((*CR)[CAR]->op_code == 12)
		d[0] %= IDX_MOD;
	d2[0] = (*CR)[CAR]->pc + d[0];
	d2[1] = ft_limit(d2[0]);
	ft_copy_car(CR, CW, d2[1]);
	CAR++;
	if (CW->v30 == 1)
	{
		ft_printf("P %4i | %s %hd (%i)\n", \
		(*CR)[CAR]->id, op_tab[(*CR)[CAR]->op_code - 1].name, d[1], d2[0]);
		ft_v30(CW, (*CR)[CAR], 3);
	}
	(*CR)[CAR]->pc = ft_limit((*CR)[CAR]->pc + 3);
	COL_CAR++;
}

void		ft_aff(t_carriage *carriage, t_corewar *corewar)
{
	int		d;

	d = ft_argument(CW->arena[ft_limit(CR->pc + 1)], CR, CW, 0);
	if ((AR_TYPES & 192) == 64 && d < REG_NUMBER && d >= 0)
	{
		if (CW->v30 == 1 || CW->aff == 1)
		{
			ft_printf("Aff: %c\n", ((char)(CR->registrs[d] % 256)));
			ft_v30(CW, CR, 3);
		}
		CR->pc = ft_limit(CR->pc + 3);
	}
	else
		ft_wrong_ar_types(CR, CW, AR_TYPES, 1);
}
