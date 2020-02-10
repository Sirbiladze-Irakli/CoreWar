/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:08:24 by cdubuque          #+#    #+#             */
/*   Updated: 2020/01/28 18:47:13 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int			ft_degree_16(int j)
{
	int		k;

	k = 16;
	if (j == 0)
		return (1);
	else
	{
		++j;
		while (--j > 1)
			k *= k;
	}
	return (k);
}

int			ft_in_ten(char *s)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = 0;
	while (s[++i] == '0')
		;
	s = ft_free_strdup(s, i);
	i = ft_strlen(s);
	while (--i >= 0)
		k += (s[i] - '0') * ft_degree_16(++j);
	return (k);
}

void		ft_exec_code(t_player **players, int *mas, int i, int pos)
{
	int		d;
	char	*s;

	d = -1;
	pos -= 1;
	if (!(players[i]->exec_code = (int *)malloc(sizeof(int) \
	* (players[i]->code_size + 1))))
		exit(0);
	while (mas[++pos] != 22222222)
		players[i]->exec_code[++d] = mas[pos];
	if (d != players[i]->code_size - 1)
	{
		s = ft_strdup("Error: File ");
		ft_first_free_join(&s, players[i]->fullname);
		ft_first_free_join(&s, " is too small to be a champion\n");
		error(s);
	}
}

void		ft_champion_comment(t_player **players, int *mas, int i, int pos)
{
	int		d;

	pos -= 1;
	d = -1;
	while (mas[++pos] != 0)
	{
		if (d == COMMENT_LENGTH)
			error("Too long player's name\n");
		players[i]->comment[++d] = (char)(mas[pos]);
	}
}
