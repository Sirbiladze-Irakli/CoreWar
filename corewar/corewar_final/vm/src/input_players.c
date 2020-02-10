/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:05:37 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 19:51:41 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_champions_up(char *s, int c, t_player **players, char *s1)
{
	int		i;

	i = MAX_PLAYERS;
	while (players[--i]->name == NULL)
		;
	if (i + 1 == MAX_PLAYERS)
		error("Too many champions\n");
	while (i >= c - 1)
	{
		free(players[i + 1]->name);
		free(players[i + 1]->fullname);
		players[i + 1]->name = ft_strdup(players[i]->name);
		players[i + 1]->n = players[i]->n;
		players[i + 1]->fullname = ft_strdup(players[i]->fullname);
		--i;
	}
	free(players[c - 1]->name);
	free(players[c - 1]->fullname);
	players[c - 1]->name = ft_strdup(s);
	players[c - 1]->n = 1;
	players[c - 1]->fullname = ft_strdup(s1);
}

void		ft_split_s(char **s)
{
	char	**arr;
	int		i;

	i = -1;
	arr = ft_strsplit(*s, '/');
	while (arr[++i + 1] != NULL)
		;
	free(*s);
	*s = ft_strdup(arr[i]);
	ft_split_free(arr);
}

void		ft_new_player_c(char *s, int *c, t_player **players, char *s1)
{
	++(*c);
	if (*c > MAX_PLAYERS)
		error("Too many champions\n");
	if (players[*c - 1]->name == NULL)
	{
		players[*c - 1]->name = ft_strdup(s);
		players[*c - 1]->fullname = ft_strdup(s1);
		ft_strcut(&(players[*c - 1]->dis_asm_name), s1, ft_strlen(s1) - 3);
		ft_first_free_join(&players[*c - 1]->dis_asm_name, "s");
	}
	else
	{
		while (*c <= MAX_ARGS_NUMBER && players[++(*c) - 1]->name != NULL)
			;
		if (*c > MAX_PLAYERS)
			error("Too many champions\n");
		players[*c - 1]->name = ft_strdup(s);
		players[*c - 1]->fullname = ft_strdup(s1);
		players[*c - 1]->dis_asm_name = ft_strdup(s1);
		ft_strcut(&(players[*c - 1]->dis_asm_name), s1, ft_strlen(s1) - 3);
		ft_first_free_join(&players[*c - 1]->dis_asm_name, "s");
	}
}

void		ft_new_player_flag(char *s, int *c, t_player **players, char *s1)
{
	if (players[*c - 1]->name == NULL)
	{
		players[*c - 1]->name = ft_strdup(s);
		players[*c - 1]->n = 1;
		players[*c - 1]->fullname = ft_strdup(s1);
	}
	else if (players[*c - 1]->name != NULL && players[*c - 1]->n == 1)
		error("Duble flag -n\n");
	else
		ft_champions_up(s, *c, players, s1);
	*c = 0;
}

void		ft_give_number(char *s, int *c, t_player **players, int d)
{
	char	**arr;
	char	*s1;
	char	*s2;

	s1 = ft_strdup(s);
	s2 = ft_strdup(s);
	if (ft_strchr(s2, '/'))
		ft_split_s(&s2);
	arr = ft_strsplit(s2, '.');
	if (d == 0)
		ft_new_player_c(arr[0], c, players, s1);
	else
		ft_new_player_flag(arr[0], c, players, s1);
	ft_split_free(arr);
	free(s2);
	free(s1);
}
