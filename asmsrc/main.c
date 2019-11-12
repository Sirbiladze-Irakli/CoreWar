/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:38:51 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/12 18:19:32 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		output(int var)
{
	return ;
}

void		init_struct(t_cw *corewar)
{
	return ;
}

int			main(int ac, char **av)
{
	t_cw	corewar;

	if (ac == 2)
	{
		init_struct(&corewar);
		arg_reader(**av);
	}
	exit(0);
}