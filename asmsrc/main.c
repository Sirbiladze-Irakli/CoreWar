/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:38:51 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/19 18:23:59 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		output(char *str)
{
	if (ft_strcmp(str, "OK"))
		write(1, str, ft_strlen(str));
	exit(0);
}

void		init_struct(t_cw *corewar)
{
	// corewar->line = (char *)malloc(sizeof(char) * 10);
	corewar->output_file = NULL;
	corewar->ret = 0;
	corewar->in = 0;
	corewar->error_line = 0;
	corewar->error_sym = 0;
}

int			main(int ac, char **av)
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