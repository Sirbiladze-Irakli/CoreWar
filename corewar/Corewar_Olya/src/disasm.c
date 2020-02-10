/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:58:46 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 16:49:25 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		ft_dis_write(t_player *players, int j, int fd, int op)
{
	int		d;
	char	*s;

	d = ft_op_code(players->exec_code[j], op);
	if (op == 0)
		players->move++;
	if (d == 1)
		s = ft_strjoin("r", ft_itoa(players->exec_code[j + players->move++]));
	else if (d == 2)
	{
		if (players->exec_code[j - 1] > 8 && players->exec_code[j - 1] < 16 \
		&& players->exec_code[j - 1] != 13)
			ft_dis_dir_2(&s, players, j, fd);
		else
			ft_dis_dir_4(&s, players, j, fd);
	}
	else
	{
		s = ft_itoa(((players->exec_code[j + players->move]) << 8) \
			| (players->exec_code[j + players->move + 1]));
		players->move += 2;
	}
	write(fd, s, ft_strlen(s));
}

void		ft_dis_dir_2(char **s, t_player *players, int j, int fd)
{
	char	c;

	c = '%';
	write(fd, &c, 1);
	*s = ft_itoa(((players->exec_code[j + players->move]) << 8) \
	| (players->exec_code[j + players->move + 1]));
	players->move += 2;
}

void		ft_dis_dir_4(char **s, t_player *players, int j, int fd)
{
	char	c;

	c = '%';
	write(fd, &c, 1);
	*s = ft_itoa(((players->exec_code[j + players->move]) << 24) \
	| ((players->exec_code[j + players->move + 1]) << 16)
	| ((players->exec_code[j + players->move + 2]) << 8)
	| (players->exec_code[j + players->move + 3]));
	players->move += 4;
}

void		ft_if_dis_write(t_player *players, int now_pos, int fd)
{
	int		op;
	char	*s;

	op = -1;
	write(fd, g_op_tab[now_pos - 1].name, \
	ft_strlen(g_op_tab[now_pos - 1].name));
	write(fd, " ", 1);
	if (now_pos != 1 && now_pos != 9 && \
	now_pos != 12 && now_pos != 15)
	{
		while (++op < g_op_tab[now_pos - 1].col_arg)
		{
			ft_dis_write(players, players->now_pos + 1, fd, op);
			if (op < g_op_tab[now_pos - 1].col_arg)
				write(fd, " ", 1);
		}
	}
	else
	{
		if (now_pos == 1)
			ft_dis_dir_4(&s, players, players->now_pos + 1, fd);
		else
			ft_dis_dir_2(&s, players, players->now_pos + 1, fd);
		write(fd, s, ft_strlen(s));
	}
}

void		ft_disassembler(t_corewar *corewar, t_player **players)
{
	int		i;
	int		fd;

	i = -1;
	while (++i < corewar->col_play)
	{
		if (!(fd = open(players[i]->dis_asm_name, O_CREAT | O_RDWR, 0644)))
			ft_printf("Can't create file\n");
		ft_header_disasm(players[i], fd);
		while (players[i]->now_pos < players[i]->code_size)
		{
			ft_if_dis_write(players[i], \
			players[i]->exec_code[players[i]->now_pos], fd);
			players[i]->now_pos += players[i]->move + 1;
			players[i]->move = 0;
			write(fd, "\n", 1);
		}
	}
}
