/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:03:47 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/18 16:14:48 by jormond-         ###   ########.fr       */
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
			corewar->arena[players[c]->ST_POI + i] = (unsigned char)players[c]->exec_code[i];
	}
	// i = -1;
	// while (++i < MEM_SIZE)
	// {
	// 	if (corewar->arena[i] != 0)
	// 	printf("\e[1;34m%d\e[0m ", corewar->arena[i]);
	// 	else
	// 		printf("%d ", corewar->arena[i]);
	// 	if (i / 100 == 0 && i >= 100)
	// 		printf("\n");
	// }
}

void		ft_carriege_init(t_carriage ***carriege, t_player **players, t_corewar *corewar)
{
	int		c;
	int		i;

	c = -1;
	if (!((*carriege) = (t_carriage **)malloc(sizeof(t_carriage *) * COL_PL)))
		exit(0);
	while (++c < COL_PL)
	{
		if (!((*carriege)[c] = (t_carriage *)malloc(sizeof(t_carriage))))
			exit(0);
		(*carriege)[c]->ID = COL_PL - c;
		(*carriege)[c]->carry = 0;
		(*carriege)[c]->op_code = -1;
		(*carriege)[c]->cyc_live = -1;
		(*carriege)[c]->PC = players[COL_PL - c - 1]->ST_POI;
		(*carriege)[c]->byte_jump = -1;
		(*carriege)[c]->registrs[0] = c - COL_PL;
		i = 0;
		while (++i < REG_NUMBER)
			(*carriege)[c]->registrs[i] = 0;
	}
}

void		ft_arena(t_player **players, t_corewar *corewar)
{
	int			i;
	int			c;
	t_carriage	**carriege;

	i = -1;
	c = -1;
	while(++i < MEM_SIZE)
		(corewar)->arena[i] = 0;
	while (++c < MAX_PLAYERS && players[c]->name != NULL)
		;
	COL_PL = c;
	c = 0;
	while (++c < COL_PL)
		players[c]->ST_POI = players[c - 1]->ST_POI + MEM_SIZE / COL_PL;
	ft_arena_exec_code(players, corewar);
	ft_carriege_init(&carriege, players, corewar);
}