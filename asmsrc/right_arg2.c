/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:32:12 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/02 19:10:23 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			distrib2(t_cw *corewar, t_ls *tmp, char *str, char flag)
{
	int			res;

	res = 0;
	if (flag == '5')
	{
		res = check_ind(corewar, tmp, str);
		if (res == 0)
			return ;
		res = check_dir(corewar, tmp, str);
	}
	else if (flag == '6')
	{
		res = check_reg(corewar, tmp, str);
		if (res == 0)
			return ;
		res = check_dir(corewar, tmp, str);
		if (res == 0)
			return ;
		res = check_ind(corewar, tmp, str);
	}
	if (res > 0)
		wrong_instr(corewar);
}

int	            check_reg(t_cw *corewar, t_ls *tmp, char *str)
{
	if (str[0] == 'r' && ((str[1] >= '0' && str[1] <= '9')
			|| (str[2] >= '0' && str[2] <= '9')))
	{
		corewar->res += 1;
		tmp->label = REGISTER;
		return (0);
	}
	return (1);
}

int	            check_dir(t_cw *corewar, t_ls *tmp, char *str)
{
	if (str[0] == '%' && str[1] == ':')
	{
		corewar->res += corewar->dir;
		tmp->label = DIRECT_LABEL;
		return (0);
	}
	else if (str[0] == '%' && str[1] >= '0' && str[1] <= '9')
	{
		corewar->res += corewar->dir;
		tmp->label = DIRECT;
		return (0);
	}
	return (1);
}

int	            check_ind(t_cw *corewar, t_ls *tmp, char *str)
{
	int			res;
	char		*check;

	res = ft_atoi(str);
	check = ft_itoa(res);
	if (ft_strcmp(str, check))
		return (1);
	if (str[0] >= '0' && str[0] <= '9')
	{
		corewar->res += 2;
		tmp->label = INDIRECTION;
		return (0);
	}
	return (1);
}
