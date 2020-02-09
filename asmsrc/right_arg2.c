/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_arg2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:32:12 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/09 16:24:58 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			distrib2(t_ls *tmp, char *str, char flag)
{
	int			res;

	res = 0;
	if (flag == '5')
	{
		res = check_ind(tmp, str);
		if (res == 0)
			return ;
		res = check_dir(tmp, str);
	}
	else if (flag == '6')
	{
		res = check_reg(tmp, str);
		if (res == 0)
			return ;
		res = check_dir(tmp, str);
		if (res == 0)
			return ;
		res = check_ind(tmp, str);
	}
	if (res > 0)
		wrong_instr(tmp, str);
}

int				check_reg(t_ls *tmp, char *str)
{
	int			error;
	regex_t		reg;
	regmatch_t	pm;

	error = regcomp(&reg, T_REG_PATTERN, REG_EXTENDED);
	if (!regexec(&reg, str, 0, &pm, 0))
	{
		tmp->label = REGISTER;
		regfree(&reg);
		return (0);
	}
	regfree(&reg);
	return (1);
}

int				check_dir(t_ls *tmp, char *str)
{
	int			error;
	regex_t		reg;
	regex_t		lreg;
	regmatch_t	pm;

	error = regcomp(&reg, T_DIR_PATTERN, REG_EXTENDED);
	error = regcomp(&lreg, T_DIR_LABEL_PATTERN, REG_EXTENDED);
	if (!regexec(&reg, str, 0, &pm, 0))
	{
		tmp->label = DIRECT;
		regfree(&lreg);
		regfree(&reg);
		return (0);
	}
	if (!regexec(&lreg, str, 0, &pm, 0))
	{
		tmp->label = DIRECT_LABEL;
		regfree(&lreg);
		regfree(&reg);
		return (0);
	}
	regfree(&lreg);
	regfree(&reg);
	return (1);
}

int				check_ind(t_ls *tmp, char *str)
{
	int			error;
	regex_t		reg;
	regex_t		lreg;
	regmatch_t	pm;

	error = regcomp(&reg, T_IND_PATTERN, REG_EXTENDED);
	error = regcomp(&lreg, T_IND_LABEL_PATTERN, REG_EXTENDED);
	if (!regexec(&reg, str, 0, &pm, 0))
	{
		tmp->label = INDIRECTION;
		regfree(&reg);
		regfree(&lreg);
		return (0);
	}
	if (!regexec(&lreg, str, 0, &pm, 0))
	{
		tmp->label = INDIRECT_LABEL;
		regfree(&lreg);
		regfree(&reg);
		return (0);
	}
	regfree(&lreg);
	regfree(&reg);
	return (1);
}
