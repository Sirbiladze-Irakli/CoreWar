/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:59:43 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/15 15:58:14 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_create_players(t_player ***players, t_corewar **corewar)
{
	int		c;

	c = -1;
	if (!((*players) = (t_player **)malloc(sizeof(t_player *) * MAX_PLAYERS)))
		exit(0);
	while (++c < MAX_PLAYERS)
	{
		if (!((*players)[c] = (t_player *)malloc(sizeof(t_player))))
			exit(0);
		NAME = NULL;
		(*players)[c]->n = 0;
		(*players)[c]->fullname = NULL;
		(*players)[c]->code_size = 0;
		(*players)[c]->entry_point = 0;
	}
	if (!((*corewar) = (t_corewar *)malloc(sizeof(t_corewar))))
		exit(0);
	(*corewar)->last_player = -1;
	(*corewar)->start_cycles = -1;
	(*corewar)->col_live = -1;
	(*corewar)->cycles_to_die = CYCLE_TO_DIE;
	(*corewar)->col_check = -1;
}

void		ft_welcome_champions(t_player **players)
{
	int		i;
	char	*s;

	i = -1;
	write(1, "Introducing contestants...\n", 27);
	while (++i < MAX_PLAYERS && players[i]->name != NULL)
	{
		s = ft_strdup("* Player ");
		ft_first_free_join(&s, ft_itoa(i + 1));
		ft_first_free_join(&s, ", weighing ");
		ft_first_free_join(&s, ft_itoa(players[i]->code_size));
		ft_first_free_join(&s, " bytes, \"");
		ft_first_free_join(&s, players[i]->player_name);
		ft_first_free_join(&s, "\" (\"");
		ft_first_free_join(&s, players[i]->comment);
		ft_first_free_join(&s, "\") !");
		ft_first_free_join(&s, "\n");
		write(1, s, ft_strlen(s));
	}
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
	ft_create_players(&players, &corewar);
	while (++i < ac)
	{
		if (ft_strstr(av[i], ".cor") != NULL)
		{
			if (n != 0)
				ft_give_number(av[i], &n, players, 1);
			else
				ft_give_number(av[i], &c, players, 0);
		}
		else if (!(ft_strcmp(av[i], "-n")))
		{
			n = ft_atoi(av[++i]);
			if (n > MAX_PLAYERS || n < 1)
				error("Incorrect player's number\n");
		}
	}
	ft_validation(players);
	ft_arena(players, corewar);
	// ft_welcome_champions(players);
	exit(0);
}