/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:03:05 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/09 17:22:16 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			right_arg(t_cw *corewar, t_parse *parser, t_ls *tmp, char *str)
{
	if (parser->countargs == 1)
		first(corewar, tmp, str);
	else if (parser->countargs == 2)
		second(corewar, tmp, str);
	else if (parser->countargs == 3)
		third(corewar, tmp, str);
}

void			first(t_cw *corewar, t_ls *tmp, char *str)
{
	int			i;

	i = tab(corewar->lastinstr);
	if (op_tab[i].args[0] == '1')
		distrib(tmp, str, '1');
	else if (op_tab[i].args[0] == '2')
		distrib(tmp, str, '2');
	else if (op_tab[i].args[0] == '5')
		distrib(tmp, str, '5');
	else if (op_tab[i].args[0] == '6')
		distrib(tmp, str, '6');
}

void			second(t_cw *corewar, t_ls *tmp, char *str)
{
	int			i;

	i = tab(corewar->lastinstr);
	if (op_tab[i].args[1] == '1')
		distrib(tmp, str, '1');
	else if (op_tab[i].args[1] == '3')
		distrib(tmp, str, '3');
	else if (op_tab[i].args[1] == '4')
		distrib(tmp, str, '4');
	else if (op_tab[i].args[1] == '6')
		distrib(tmp, str, '6');
}

void			third(t_cw *corewar, t_ls *tmp, char *str)
{
	int			i;

	i = tab(corewar->lastinstr);
	if (op_tab[i].args[2] == '1')
		distrib(tmp, str, '1');
	else if (op_tab[i].args[2] == '3')
		distrib(tmp, str, '3');
}

void			distrib(t_ls *tmp, char *str, char flag)
{
	int			res;

	res = 0;
	if (flag == '1')
		res = check_reg(tmp, str);
	else if (flag == '2')
		res = check_dir(tmp, str);
	else if (flag == '3')
	{
		res = check_reg(tmp, str);
		if (res == 0)
			return ;
		res = check_dir(tmp, str);
	}
	else if (flag == '4')
	{
		res = check_reg(tmp, str);
		if (res == 0)
			return ;
		res = check_ind(tmp, str);
	}
	else
		distrib2(tmp, str, flag);
	if (res > 0)
		wrong_instr(tmp, str);
}
