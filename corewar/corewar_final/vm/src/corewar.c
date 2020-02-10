/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:59:43 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 19:51:19 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_welcome_champions(t_player **players)
{
	int		i;

	i = -1;
	ft_printf("Introducing contestants...\n");
	while (++i < MAX_PLAYERS && players[i]->name != NULL)
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n", i + 1,\
		players[i]->code_size, players[i]->player_name, players[i]->comment);
}

void		ft_winner(t_player **players, t_corewar *corewar)
{
	ft_printf("Contestant %i, \"%s\", has won !\n", \
	corewar->last_player, players[corewar->last_player - 1]->player_name);
}

void		ft_flags(t_corewar *corewar, char **s, int *i, int *n)
{
	if (!(ft_strcmp(s[*i], "-n")))
	{
		(*n) = ft_atoi(s[++(*i)]);
		if ((*n) > MAX_PLAYERS || (*n) < 1)
			error("Incorrect player's number\n");
		if ((*n) > corewar->max_n)
			corewar->max_n = (*n);
	}
	else if (!(ft_strcmp(s[*i], "-v")) && !(ft_strcmp(s[++(*i)], "30")))
		corewar->v30 = 1;
	else if (!(ft_strcmp(s[*i], "-dump")))
		corewar->dump = ft_atoi(s[++(*i)]);
	else if (!(ft_strcmp(s[*i], "-asm")))
		corewar->dis_asm = 1;
	else if (!(ft_strcmp(s[*i], "-a")))
		corewar->aff = 1;
	else if (!(ft_strcmp(s[*i], "-viz")))
		corewar->viz = 1;
	else
		error("Wrong file\n");
}

void		ft_play(t_corewar *corewar, t_player **players, int ac)
{
	if (ac == 1)
		error("No players!\n");
	corewar->last_player = corewar->col_play;
	if (CW->max_n > COL_PL)
		error("Too much -n number");
	ft_validation(players);
	if (corewar->dis_asm == 1)
		ft_disassembler(corewar, players);
	else
	{
		ft_welcome_champions(players);
		ft_arena(players, corewar);
		if (corewar->dump < 0 || corewar->dump > corewar->start_cycles + 1)
			ft_winner(players, corewar);
		if (corewar->dump > -1 && corewar->dump <= corewar->start_cycles)
			ft_print_map(corewar);
	}
	exit(1);
}

int			main(int ac, char *av[])
{
	int			i;
	int			c;
	int			n;
	t_player	**players;
	t_corewar	*corewar;

	i = 0;
	c = 0;
	n = 0;
	ft_create_players(&players);
	ft_create_corewar(&corewar);
	while (++i < ac)
	{
		if (ft_strstr(av[i], ".cor") != NULL)
		{
			if (n != 0)
				ft_give_number(av[i], &n, players, 1);
			else
				ft_give_number(av[i], &c, players, 0);
			corewar->col_play++;
		}
		else
			ft_flags(corewar, av, &i, &n);
	}
	ft_play(corewar, players, ac);
}
