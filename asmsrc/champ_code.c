/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:03:53 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/20 17:37:29 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            champ_code(t_cw *corewar, int out, t_ls *list)
{
	t_ls        *tmp;
	uint8_t     type;
	char        c;

	tmp = list;
	type = 0;
	c = tmp->label;
	corewar->dir = dir_size(tmp);
	// printf("%d - instrbytes before --->> ", tmp->instrbytes);
	tmp->instrbytes += codetype(tmp) + 1;
	// printf("%d - instrbytes\n", tmp->instrbytes);
	// printf("%d bytes before --->> ", corewar->bytes);
	corewar->bytes += tmp->instrbytes;
	// printf("%d bytes\n", corewar->bytes);
	write(out, &c, 1);
	if (tmp->label != LIVE && tmp->label != ZJMP && tmp->label != FORK
	&& tmp->label != LFORK)
	{
		define_types(corewar, tmp, &type);
		c = type;
		write(out, &c, 1);
	}
	how_many_args(corewar, tmp);
	write_args(corewar, out, tmp);
}

void            define_types(t_cw *corewar, t_ls *tmp, uint8_t *type)
{
	corewar->iter = 0;
	how_many_args(corewar, tmp);
	while (corewar->counter--)
	{
		tmp = tmp->next;
		if (ft_strchr(tmp->token, 'r'))
			reg_fill(corewar, type);
		else if (ft_strchr(tmp->token, '%'))
			dir_fill(corewar, type);
		else
			ind_fill(corewar, type);
		corewar->iter++;
	}
}

void            reg_fill(t_cw *corewar, uint8_t *type)
{
	if (corewar->iter == 0)
		(*type) |= 64;
	else if (corewar->iter == 1)
		(*type) |= 16;
	else if (corewar->iter == 2)
		(*type) |= 4;
}

void            dir_fill(t_cw *corewar, uint8_t *type)
{
	if (corewar->iter == 0)
		(*type) |= 128;
	else if (corewar->iter == 1)
		(*type) |= 32;
	else if (corewar->iter == 2)
		(*type) |= 8;
}

void            ind_fill(t_cw *corewar, uint8_t *type)
{
	if (corewar->iter == 0)
		(*type) |= 192;
	else if (corewar->iter == 1)
		(*type) |= 48;
	else if (corewar->iter == 2)
		(*type) |= 12;
}
