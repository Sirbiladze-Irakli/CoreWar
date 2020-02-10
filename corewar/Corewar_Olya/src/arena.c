/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:03:47 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 18:20:56 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_arena_exec_code(t_player **players, t_corewar *corewar)
{
	int		c;
	int		i;

	c = -1;
	while (++c < COL_PL)
	{
		i = -1;
		while (++i < players[c]->code_size)
			corewar->arena[players[c]->start + i] = \
			(unsigned char)players[c]->exec_code[i];
	}
}

void		ft_first_carriages(t_carriage **carriage, t_player **players, \
t_corewar *corewar, int c)
{
	int		i;

	if (!((*carriage) = (t_carriage *)malloc(sizeof(t_carriage))))
		exit(0);
	(*carriage)->id = COL_PL - c;
	(*carriage)->carry = 0;
	(*carriage)->op_code = 0;
	(*carriage)->cyc_live = 0;
	(*carriage)->pc = players[COL_PL - c - 1]->start;
	(*carriage)->arg_types = (*carriage)->pc + 1;
	(*carriage)->byte_jump = -1;
	(*carriage)->registrs[0] = c - COL_PL;
	(*carriage)->registrs[REG_NUMBER] = c - COL_PL;
	(*carriage)->cyc_to_op = 0;
	(*carriage)->move = 1;
	i = 0;
	while (++i < REG_NUMBER)
		(*carriage)->registrs[i] = 0;
}

void		ft_carriage_init(t_carriage ***carriage, t_player **players, \
t_corewar *corewar)
{
	int		c;

	c = -1;
	if (!((*carriage) = (t_carriage **)malloc(sizeof(t_carriage *) * COL_PL)))
		exit(0);
	while (++c < COL_PL)
		ft_first_carriages(&(*carriage)[c], players, corewar, c);
	COL_CAR = COL_PL;
	CAR_MAS = COL_PL;
	corewar->plus_id = COL_CAR;
}

void		ft_arena(t_player **players, t_corewar *corewar)
{
	int			i;
	int			c;
	t_carriage	**carriage;

	i = -1;
	c = -1;
	if (!(CW->arena = (unsigned char *)malloc(sizeof(unsigned char) \
	* MEM_SIZE)))
		exit(0);
	while (++i < MEM_SIZE)
		(CW)->arena[i] = 0;
	while (++c < MAX_PLAYERS && players[c]->name != NULL)
		;
	COL_PL = c;
	c = 0;
	while (++c < COL_PL)
		players[c]->start = players[c - 1]->start + MEM_SIZE / COL_PL;
	ft_arena_exec_code(players, CW);
	ft_carriage_init(&carriage, players, CW);
	ft_lets_go_war(corewar, &carriage);
}
