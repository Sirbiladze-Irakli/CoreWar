/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:38:51 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/20 17:07:51 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			errors(t_cw *corewar, int var, int shift)
{
	if ((corewar->name > 1 || corewar->name == 0)
	&& ft_strcmp(corewar->line, ".name"))
	{
		corewar->esym -= shift;
		error_out(corewar, 1);
		write(1, " COMMAND_NAME \".name\"\n", 23);
	}
	else if ((corewar->comment > 1 || corewar->comment == 0)
	&& ft_strcmp(corewar->line, ".comment"))
	{
		corewar->esym -= shift;
		error_out(corewar, 1);
		write(1, " COMMAND_COMMENT \".comment\"\n", 28);
	}
	else if (var == 2)
		error_out(corewar, 2);
	exit(0);
}

void			error_out(t_cw *corewar, int var)
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
	corewar->tokens = NULL;
	corewar->instruct = NULL;
	corewar->bytecode = NULL;
	corewar->line = ft_strnew(1);
	corewar->res = 0;
	corewar->dir = 0;
	corewar->in = 0;
	corewar->skip = 0;
	corewar->labelpos = 0;
	corewar->eline = 1;
	corewar->typecode = 0;
	corewar->iter = 0;
	corewar->name = 0;
	corewar->bytes = 0;
	corewar->comment = 0;
	corewar->esym = 1;
	corewar->counter = 0;
}

int				main(int ac, char **av)
{
	t_cw	corewar;
	
	if (ac < 2 || ac > 2)
		output("usage : ./asm champion.s\n");
	init_struct(&corewar);
	s_reader(&corewar, av[1]);
	s_compiler(&corewar, av[1]);
	// write(1, "Writing output program to ", 26);
	// write(1, corewar.bytecode, ft_strlen(corewar.bytecode));
	// write(1, "\n", 1);
	exit(0);
}