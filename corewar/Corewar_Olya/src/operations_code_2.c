/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_code_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:04:57 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 18:22:49 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_reg_for_and_or_xor(t_carriage *carriage, int *d)
{
	if (CR->op_code == 6)
		CR->registrs[d[2]] = d[0] & d[1];
	else if (CR->op_code == 7)
		CR->registrs[d[2]] = d[0] | d[1];
	else
		CR->registrs[d[2]] = d[0] ^ d[1];
	ft_carry(CR, d[2]);
	CR->pc = ft_limit(CR->pc + CR->move);
}

void		ft_and_or_xor(t_carriage *carriage, t_corewar *corewar)
{
	int		d[3];

	ft_what_arguments(d, CR, CW, 3);
	if ((AR_TYPES & 192) != 0 && (AR_TYPES & 48) != 0 && (AR_TYPES & 12) == 4 \
	&& !(ft_check_reg(AR_TYPES, 7, d)))
	{
		ft_reg_value(d, 6, AR_TYPES, CR);
		if ((AR_TYPES & 192) == 192)
			d[0] = ft_record_from_arena(CR->pc + d[0] % IDX_MOD, CW);
		if ((AR_TYPES & 48) == 48)
			d[1] = ft_record_from_arena(CR->pc + d[1] % IDX_MOD, CW);
		if (CW->v30 == 1)
		{
			ft_printf("P %4i | %s %i %i r%i\n", CR->id, \
			g_op_tab[CR->op_code - 1].name, d[0], d[1], d[2] + 1);
			ft_v30(CW, CR, CR->move);
		}
		ft_reg_for_and_or_xor(CR, d);
	}
	else
		ft_wrong_ar_types(carriage, corewar, AR_TYPES, 3);
}

void		ft_zjmp(t_carriage *carriage, t_corewar *corewar)
{
	short		d;

	ft_record_short(CW, CR, &d);
	if (CR->carry == 1)
	{
		if (CW->v30 == 1)
			ft_printf("P %4i | zjmp %i OK\n", CR->id, d);
		d %= IDX_MOD;
		CR->pc = ft_limit(CR->pc + d);
	}
	else
	{
		if (CW->v30 == 1)
		{
			ft_printf("P %4i | zjmp %i FAILED\n", CR->id, d);
			ft_v30(CW, CR, 3);
		}
		CR->pc = ft_limit(CR->pc + 3);
	}
}

void		ft_v_30_ldi_lldi(t_carriage *carriage, t_corewar *corewar, int *d)
{
	char	*s;

	s = ft_strdup("with pc");
	if (CR->op_code == 10)
		ft_first_free_join(&s, " and mod");
	ft_printf("P %4i | %s %i %i r%i\n %20s %i + %i = %i (%s %i)\n", \
	CR->id, g_op_tab[CR->op_code - 1].name, d[0], d[1], d[2] + 1, \
	"| -> load from", d[0], d[1], d[0] + d[1], s, d[3]);
	ft_v30(CW, CR, CR->move);
}

void		ft_ldi_and_lldi(t_carriage *carriage, t_corewar *corewar)
{
	int		d[4];

	ft_what_arguments(d, CR, CW, 3);
	if (!(ft_check_reg(AR_TYPES, 7, d)) && (AR_TYPES & 192) != 0 && \
	((AR_TYPES & 48) == 16 || (AR_TYPES & 48) == 32) && (AR_TYPES & 12) == 4)
	{
		ft_reg_value(d, 6, AR_TYPES, CR);
		if ((AR_TYPES & 192) == 192)
			d[0] = ft_record_from_arena(CR->pc + d[0], CW);
		if (CR->op_code == 10)
			d[3] = CR->pc + (d[0] + d[1]) % IDX_MOD;
		else
			d[3] = CR->pc + (d[0] + d[1]);
		if (CW->v30 == 1)
			ft_v_30_ldi_lldi(carriage, corewar, d);
		CR->registrs[d[2]] = ft_record_from_arena(d[3], CW);
		if (CR->op_code != 10)
			ft_carry(CR, d[2]);
		CR->pc = ft_limit(CR->pc + CR->move);
	}
	else
		ft_wrong_ar_types(CR, CW, AR_TYPES, 3);
}
