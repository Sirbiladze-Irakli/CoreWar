/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:52:33 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/05 17:53:38 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_create_players(t_player ***players)
{
	int		c;

	c = -1;
	if (!((*players) = (t_player **)malloc(sizeof(t_player *) * MAX_PLAYERS)))
		exit(0);
	while (++c < MAX_PLAYERS)
	{
		if (!((*players)[c] = (t_player *)malloc(sizeof(t_player))))
			exit(0);
		(*players)[c]->name = NULL;
		(*players)[c]->n = 0;
		(*players)[c]->fullname = NULL;
		(*players)[c]->dis_asm_name = NULL;
		(*players)[c]->code_size = 0;
		(*players)[c]->start = 0;
		(*players)[c]->move = 0;
		(*players)[c]->now_pos = 0;
	}
}

void		ft_create_corewar(t_corewar **corewar)
{
	if (!((*corewar) = (t_corewar *)malloc(sizeof(t_corewar))))
		exit(0);
	(*corewar)->start_cycles = 0;
	(*corewar)->col_live = 0;
	(*corewar)->v30 = 0;
	(*corewar)->col_play = 0;
	(*corewar)->cycles_to_die = CYCLE_TO_DIE;
	(*corewar)->col_check = 1;
	(*corewar)->active_car = -1;
	(*corewar)->plus_ID = -1;
	(*corewar)->dump = -1;
	(*corewar)->dis_asm = -1;
	(*corewar)->cycle = 0;
	(*corewar)->aff = 0;
	(*corewar)->max_n = 0;
	(*corewar)->viz = 0;
}
