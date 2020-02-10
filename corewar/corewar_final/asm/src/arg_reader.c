/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:30:14 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/10 18:59:20 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			take_tokens(t_cw *corewar)
{
	read_line(corewar->in, &corewar->line);
	parse(corewar);
}

void			s_reader(t_cw *corewar, char *av)
{
	char		*ext;

	if (!(ext = ft_strrchr(av, '.')))
		output("Can't read input file\n");
	if (ft_strcmp(ext, ".s"))
		output("Can't read input file\n");
	corewar->bytecode = ft_strnew(ext - av + 4);
	ft_strncpy(corewar->bytecode, av, ext - av + 1);
	ft_strncpy(ft_strrchr(corewar->bytecode, '.') + 1, "cor", 3);
}

void			read_line(int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			output("Can't read this file");
		buf[ret] = '\0';
		ft_join_free(line, buf);
	}
}
