/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brickon- <brickon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:47:07 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 17:43:31 by brickon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_header_disasm(t_player *players, int fd)
{
	char	*s;

	s = ft_strdup(".name \"");
	ft_first_free_join(&s, players->name);
	ft_first_free_join(&s, "\"\n");
	ft_first_free_join(&s, ".comment \"");
	ft_first_free_join(&s, players->comment);
	ft_first_free_join(&s, "\"\n\n");
	write(fd, s, ft_strlen(s));
}

void		ft_record_short(t_corewar *corewar, t_carriage *carriage, short *zn)
{
	*zn = ((corewar->arena[ft_limit(carriage->PC + carriage->move)]) << 8) \
	| (corewar->arena[ft_limit(carriage->PC + carriage->move + 1)]);
}

void		ft_print_map(t_corewar *corewar)
{
	int		i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (i % 64 == 0 && i >= 64)
			ft_printf("\n");
		if (i % 64 == 0 && (i >= 64 || i == 0))
			ft_printf("%#.4x : ", i);
		ft_printf("%.2x ", corewar->arena[i]);
	}
	ft_printf("\n");
}

void		ft_move_car(t_carriage *carriage, t_carriage *carriage_1)
{
	int		r;

	CR->ID = carriage_1->ID;
	CR->carry = carriage_1->carry;
	CR->op_code = carriage_1->op_code;
	CR->cyc_live = carriage_1->cyc_live;
	CR->PC = carriage_1->PC;
	CR->arg_types = carriage_1->arg_types;
	CR->byte_jump = carriage_1->byte_jump;
	CR->registrs[0] = carriage_1->registrs[0];
	CR->cyc_to_op = carriage_1->cyc_to_op;
	CR->move = carriage_1->move;
	r = 0;
	while (++r <= REG_NUMBER)
		CR->registrs[r] = carriage_1->registrs[r];
}

void		ft_strcut(char **s, char *d, int c)
{
	int		i;

	i = -1;
	*s = ft_strnew(c);
	while (++i < c)
		(*s)[i] = (d)[i];
}
