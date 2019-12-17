/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:57:43 by jormond-          #+#    #+#             */
/*   Updated: 2019/12/17 13:58:18 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            third_arg(t_cw *corewar, int out, t_ls *tmp)
{
	int         i;
	int         res;
	char        r;

	i = 0;
	if (tmp->token[i] == 'r')
	{
		while (tmp->token[++i] >= '0' && tmp->token[i] <= '9')
			res = res * 10 + (tmp->token[i] - '0');
		r = res;
		write(out, &r, 1);
	}
	else if (tmp->token[i] == '%')
		write_dir(corewar, out, tmp);
}

void            write_in_file(t_cw *corewar, int res, int out)
{
	char        wr[corewar->dir];
	int         i;
	int         shift;

	i = corewar->dir;
	shift = 0;
	ft_bzero(wr, corewar->dir);
	while (i--)
	{
		wr[i] = (wr[i] | res) >> shift;
		shift += 8;
	}
	write(out, wr, corewar->dir);
}