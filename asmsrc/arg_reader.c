/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:30:14 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/22 14:44:55 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            s_reader(t_cw *corewar, char *av)
{
	char	*ext;

	if (!(ext = ft_strrchr(av, '.')))
		output("Can't read input file\n");
	if (ft_strcmp(ext, ".s"))
		output("Can't read input file\n");
	corewar->bytecode = ft_strnew(ext - av + 4);
	ft_strncpy(corewar->bytecode, av, ext - av + 1);
	ft_strncpy(ft_strrchr(corewar->bytecode, '.') + 1, "cor", 3);
}

void			cor_reader(t_cw *corewar, char *av)
{
	char	*ext;

	if (!(ext = ft_strrchr(av, '.')))
		output("Can't read input file\n");
	if (ft_strcmp(ext, ".cor"))
		output("Can't read input file\n");
	corewar->bytecode = ft_strnew(ext - av + 2);
	ft_strncpy(corewar->bytecode, av, ext - av + 1);
	ft_strncpy(ft_strrchr(corewar->bytecode, '.') + 1, "s", 1);
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

// void			valid_arg(t_cw *corewar, char *av)
// {
// 	int		i;

// 	i = -1;
// 	while (av[++i])
// 	{
// 		if (av[i] == '.' && corewar->dot == 0)
// 		{
// 			if (av[i + 1] == 's' && (av[i + 2] == ' ' || av[i + 2] == '\n'
// 			|| av[i + 2] == '\t' || av[i + 2] == '\0'))
// 				corewar->dot = 1;
// 		}
// 		else if (corewar->dot == 1)
// 		{
// 			if (av[i] != ' ' && av[i] != '\t' && av[i] != '\n' && av[i] == '\0')
// 				strerror(0);
// 		}
// 	}
// }
