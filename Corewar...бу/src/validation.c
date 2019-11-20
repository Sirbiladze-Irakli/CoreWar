/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:53:00 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/18 16:18:26 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_code_size(t_player **players, int *mas, int i, int pos)
{
	char	*s;
	int		c;

	c = 0;
	s = ft_strdup(ft_unsigned(mas[pos], 16));
	while(++c < 4)
		ft_first_free_join(&s, ft_unsigned(mas[pos + c], 16));
	players[i]->code_size = ft_in_ten(s);
	if (players[i]->code_size > CHAMP_MAX_SIZE)
		error("Too large exec code size\n");
}

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

void		ft_check_magic_header(t_player **players, int *mas)
{
	char	*mh;
	char	*mh2;
	char	*mh3;
	char	*mh4;

	if (mas[0] != 0)
		error("Wrong Magic Header\n");
	mh = ft_unsigned((unsigned long long)COREWAR_EXEC_MAGIC, 16);
	mh2 = ft_unsigned((unsigned long long)mas[1], 16);
	mh2 = ft_free_strdup(mh2, 14);
	mh3 = ft_unsigned((unsigned long long)mas[2], 16);
	mh3 = ft_free_strdup(mh3, 14);
	ft_first_free_join(&mh2, mh3);
	mh4 = ft_unsigned((unsigned long long)mas[3], 16);
	mh4 = ft_free_strdup(mh4, 14);
	ft_first_free_join(&mh2, mh4);
	if (ft_strcmp(mh, mh2))
		error("Wrong Magic Header\n");
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
	int			b;
	int			*mas;

	i = -1;
	while (++i < MAX_PLAYERS && players[i]->name != NULL)
	{
		fd = open(players[i]->fullname, O_RDONLY);
		pos = lseek(fd, 0L, SEEK_END);
		if (!(mas = (int *)malloc(sizeof(int) * (pos + 1))))
			exit(0);
		mas[pos] = 22222222;
		pos = lseek(fd, 0L, SEEK_SET);
		b = -1;
		while (read(fd, buf, 1) != 0)
		{	
			mas[++b] = (int)buf[0];
			printf("%x ", mas[b]);
			if (b % 4 == 0)
				printf(" ");
			if (b % 32 == 0)
				printf("\n");
		}
		ft_check_file(players, mas, i);
		printf("\n\n\n");
	}
}
