/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:53:00 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 19:52:43 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_check_name(t_player **players, int *mas, int i, int pos)
{
	int		d;

	pos -= 1;
	d = -1;
	while (mas[++pos] != 0)
	{
		if (d == PROG_NAME_LENGTH)
			error("Too long player's name\n");
		players[i]->player_name[++d] = (char)(mas[pos]);
	}
}

void		ft_all_header(char **mh2, int *mas)
{
	char	*mh;
	int		i;

	i = 1;
	while (++i < 4)
	{
		mh = ft_unsigned((unsigned long long)mas[i], 16, 0);
		mh = ft_free_strdup(mh, 14);
		ft_first_free_join(mh2, mh);
		free(mh);
	}
}

void		ft_check_magic_header(t_player **players, int *mas)
{
	char	*mh;
	char	*mh2;

	mh = ft_unsigned((unsigned long long)COREWAR_EXEC_MAGIC, 16, 0);
	if (mas[0] == 0)
	{
		mh2 = ft_unsigned((unsigned long long)mas[1], 16, 0);
		mh2 = ft_free_strdup(mh2, 14);
	}
	else
	{
		mh2 = ft_unsigned((unsigned long long)mas[0], 16, 0);
		ft_first_free_join(&mh2, \
		ft_free_strdup(ft_unsigned((unsigned long long)mas[1], 16, 0), 14));
	}
	ft_all_header(&mh2, mas);
	ft_true_header(mh, mh2, (*players)->fullname);
	free(mh);
	free(mh2);
}

void		ft_check_file(t_player **players, int *mas, int i)
{
	long		pos;

	ft_check_magic_header(players, mas);
	pos = 4;
	ft_check_name(players, mas, i, pos);
	pos += PROG_NAME_LENGTH + 4;
	ft_code_size(players, mas, i, pos);
	pos += 4;
	ft_champion_comment(players, mas, i, pos);
	pos += COMMENT_LENGTH + 4;
	ft_exec_code(players, mas, i, pos);
}

void		ft_validation(t_player **players)
{
	int			i;
	int			fd;
	long		pos;
	char		buf[1];
	int			*mas;

	i = -1;
	while (++i < MAX_PLAYERS && players[i]->name != NULL)
	{
		fd = open(players[i]->fullname, O_RDONLY);
		if (fd == -1)
			error("Wrong file!\n");
		pos = lseek(fd, 0L, SEEK_END);
		if (!(mas = (int *)malloc(sizeof(int) * (pos + 1))))
			exit(0);
		mas[pos] = 22222222;
		pos = lseek(fd, 0L, SEEK_SET);
		pos = -1;
		while (read(fd, buf, 1) != 0)
			mas[++pos] = (int)buf[0];
		ft_check_file(players, mas, i);
		free(mas);
	}
}
