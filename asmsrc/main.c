/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:38:51 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/21 18:42:11 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			error_out(t_cw *corewar, int var, char *str)
{
	if (var == 1)
	{
		write(1, "Syntax error at token [TOKEN][", 30);
		ft_putnbr(corewar->eline);
		write(1, ":", 1);
		ft_putnbr(corewar->esym);
		write(1, "] ", 1);
	}
	else
	{
		write(1, "Lexical error at [", 18);
		ft_putnbr(corewar->eline);
		write(1, ":", 1);
		ft_putnbr(corewar->esym);
		write(1, "]", 1);
	}
	
}

void			output(char *str)
{
	if (ft_strcmp(str, "OK"))
		write(1, str, ft_strlen(str));
	exit(0);
}

void			init_struct(t_cw *corewar)
{
	if (!(corewar->inname = (char *)malloc(sizeof(char) * PROG_NAME_LENGTH)))
		output("Can't allocate a memory");
	if (!(corewar->incommands = (char *)malloc(sizeof(char) * CHAMP_MAX_SIZE)))
		output("Can't allocate a memory");
	if (!(corewar->incomment = (char *)malloc(sizeof(char) * COMMENT_LENGTH)))
		output("Can't allocate a memory");
	corewar->output_file = NULL;
	corewar->ret = 0;
	corewar->in = 0;
	corewar->eline = 0;
	corewar->pos = 4;
	corewar->name = 0;
	corewar->comment = 0;
	corewar->esym = 0;
}

int				main(int ac, char **av)
{
	t_cw	corewar;
	
	if (ac < 2 || ac > 3)
		output("usage : ./asm champion.s | ./asm -d champion.cor\n");

	init_struct(&corewar);
	if (!ft_strcmp(av[1], "-d"))
	{
		if (ac != 3)
			output("usage : ./asm champion.s | ./asm -d champion.cor\n");
		cor_reader(&corewar, av[2]);
	}
	else
	{
		s_reader(&corewar, av[1]);
		s_compiler(&corewar, av[1]);
	}
	exit(0);
}