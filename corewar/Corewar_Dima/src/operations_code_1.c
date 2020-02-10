/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_code_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <brickon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:12:26 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 17:29:37 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_live(t_carriage *carriage, t_corewar *corewar)
{
	int		d;

	d = ft_record_from_arena(CR->PC + 1, CW);
	if (CW->v30 == 1)
	{
		ft_printf("P %4i | live %i\n", CR->ID, d);
		ft_v30(CW, CR, 5);
	}
	if (d < 0)
	{
		d = ft_modul_int(d);
		if (d <= CW->col_play)
			CW->last_player = d;
	}
	CW->col_live++;
	CR->cyc_live = CW->start_cycles;
	CR->PC = ft_limit(CR->PC + 5);
}

void		ft_ld_and_lld(t_carriage *carriage, t_corewar *corewar)
{
	int		d[2];

	ft_what_arguments(d, CR, CW, 2);
	if (((AR_TYPES & 192) == 192 || (AR_TYPES & 192) == 128) && \
	(AR_TYPES & 48) == 16 && d[1] >= 0 && d[1] < REG_NUMBER)
	{
		if ((AR_TYPES & 192) == 192)
			d[0] = ft_record_from_arena(CR->PC + d[0], CW);
		if (CW->v30 == 1)
		{
			ft_printf("P %4i | %s %i r%i\n", CR->ID, \
			op_tab[CR->op_code - 1].name, d[0], d[1] + 1);
			ft_v30(CW, CR, CR->move);
		}
		CR->PC = ft_limit(CR->PC + CR->move);
		CR->registrs[d[1]] = d[0];
		ft_carry(CR, d[1]);
	}
	else
		ft_wrong_ar_types(carriage, corewar, AR_TYPES, 2);
}

void		ft_st(t_carriage *carriage, t_corewar *corewar)
{
	int		d[2];

	ft_what_arguments(d, CR, CW, 2);
	if ((AR_TYPES & 192) == 64 && ((AR_TYPES & 48) == 16 || \
	(AR_TYPES & 48) == 48) && !(ft_check_reg(AR_TYPES, 6, d)))
	{
		if ((AR_TYPES & 48) == 48)
		{
			if (CW->v30 == 1)
				ft_printf("P %4i | st r%i %i\n", CR->ID, d[0] + 1, d[1]);
			d[1] = d[1] % IDX_MOD;
			ft_record_to_arena(CW, CR->PC + d[1], CR->registrs[d[0]], abs(CR->registrs[REG_NUMBER]));
		}
		else
		{
			if (CW->v30 == 1)
				ft_printf("P %4i | st r%i %i\n", CR->ID, d[0] + 1, d[1] + 1);
			CR->registrs[d[1]] = CR->registrs[d[0]];
		}
		if (CW->v30 == 1)
			ft_v30(CW, CR, CR->move);
		CR->PC = ft_limit(CR->PC + CR->move);
	}
	else
		ft_wrong_ar_types(CR, CW, AR_TYPES, 2);
}

void		ft_add_and_sub(t_carriage *carriage, t_corewar *corewar)
{
	int		d[3];

	ft_what_arguments(d, CR, CW, 3);
	if ((AR_TYPES & 192) == 64 && (AR_TYPES & 48) == 16 && \
	(AR_TYPES & 12) == 4 && !(ft_check_reg(AR_TYPES, 7, d)))
	{
		if (CW->v30 == 1)
			ft_printf("P %4i | %s r%i r%i r%i\n", CR->ID, \
			op_tab[CR->op_code - 1].name, d[0] + 1, d[1] + 1, d[2] + 1);
		ft_reg_value(d, 6, AR_TYPES, CR);
		if (CR->op_code == 4)
			CR->registrs[d[2]] = d[0] + d[1];
		else
			CR->registrs[d[2]] = d[0] - d[1];
		if (CW->v30 == 1)
			ft_v30(CW, CR, CR->move);
		ft_carry(CR, d[2]);
		CR->PC = ft_limit(CR->PC + CR->move);
	}
	else
		ft_wrong_ar_types(CR, CW, AR_TYPES, 3);
}
