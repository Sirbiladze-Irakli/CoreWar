/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:52:56 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/10 20:18:33 by jormond-         ###   ########.fr       */
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
	parser->countargs = 0;
	parser->args = g_asm_tab[tmp->label].arg_num;
	parser->commas = parser->args;
	corewar->dir = g_asm_tab[tmp->label].dir_size;
	ft_strcpy(tmp->token, str);
	ft_strcpy(corewar->lastinstr, str);
}

void			instr_arg(t_cw *corewar, t_parse *parser, char *str)
{
	t_ls		*tmp;

	tmp = add_node(corewar);
	parser->args--;
	parser->countargs++;
	ft_strcpy(corewar->lastarg, str);
	ft_strcpy(tmp->token, str);
	right_arg(corewar, parser, tmp, str);
	if (parser->comflag == 0)
		ft_errors(corewar);
	parser->comflag = 0;
}

int				count_bytes(int label)
{
	if (label == 1 || label == 9 || label == 12 || label == 15)
		return (1);
	return (2);
}

void			wrong_instr(t_ls *tmp, char *str)
{
	ft_printf("No such label %s while attempting to dereference token [TOKEN] \
\"%s\"\n", str, tmp->token);
	exit(0);
}
