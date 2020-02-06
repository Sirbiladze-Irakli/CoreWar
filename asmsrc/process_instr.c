/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:52:56 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/06 18:28:06 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** функция определяет какая инструкция ей пришла
** и отталкиваясь от шаблона продолжает писать аргументы
** друг за другом в связный список corewar->tokens
*/

void			process_instr(t_cw *corewar, t_parse *parser, char *str)
{
	t_ls		*tmp;

	tmp = add_node(corewar);
	tmp->label = tab(str);
	corewar->res += count_bytes(tmp->label);
	parser->order = tmp->label;
	parser->comflag = 1;
	parser->countArgs = 0;
	parser->args = op_tab[tmp->label].arg_num;
	parser->commas = parser->args;
	corewar->dir = op_tab[tmp->label].dir_size;
	ft_strcpy(tmp->token, str);
	ft_strcpy(corewar->lastinstr, str);
}

void			instr_arg(t_cw *corewar, t_parse *parser, char *str)
{
	t_ls		*tmp;
	
	tmp = add_node(corewar);
	parser->args--;
	parser->countArgs++;
	ft_strcpy(corewar->lastarg, str);
	ft_strcpy(tmp->token, str);
	// count_instr(corewar, tmp, str);
	right_arg(corewar, parser, tmp, str);
	if (parser->comflag == 0)
		ft_errors(corewar, parser);
	parser->comflag = 0;
}

int				count_bytes(int label)
{
	if (label == 1 || label == 9 || label == 12 || label == 15)
		return 1;
	return 2;
}

// void			count_instr(t_cw *corewar, t_ls *tmp, char *str)
// {
// 	if (str[0] == 'r' && ((str[1] >= '0' && str[1] <= '9')
// 		|| (str[2] >= '0' && str[2] <= '9')))
// 	{
// 		corewar->res += 1;
// 		tmp->label = REGISTER;
// 	}
// 	else if (str[0] >= '0' && str[0] <= '9')
// 	{
// 		corewar->res += 2;
// 		tmp->label = INDIRECTION;
// 	}
// 	else if (str[0] == '%' && str[1] == ':')
// 	{
// 		corewar->res += corewar->dir;
// 		tmp->label = DIRECT_LABEL;
// 	}
// 	else if (str[0] == '%')
// 	{
// 		corewar->res += corewar->dir;
// 		tmp->label = DIRECT;
// 	}
// 	else
// 		wrong_instr(corewar);
// }

void			wrong_instr(t_cw *corewar, t_ls *tmp, char *str)
{
	ft_printf("No such label %s while attempting to dereference token [TOKEN]\
	\"%s\"\n", str, tmp->token);
}
