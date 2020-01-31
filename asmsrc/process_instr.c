/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:52:56 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/31 18:39:51 by jormond-         ###   ########.fr       */
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
	parser->args = op_tab[tmp->label].arg_num;
	corewar->dir = op_tab[tmp->label].dir_size;
	ft_strcpy(tmp->token, str);
	// while (corewar->line[(*i)])
	// {
		// printf("|%c|", corewar->line[(*i)]);
		// if (ft_isspace(corewar->line[(*i)]))
		// 	skip_spaces(corewar, i);
		// else if (separators(corewar->line[(*i)]))
		// 	skip_separators(corewar, i);
		// if (corewar->line[(*i)] == '\n')
		// {
		// 	new_line(corewar);
		// 	break ;
		// }
		// else
		// 	instr_arg(corewar, parser, i);
		// if (parser->args == 0)
		// 	break ;
	// }
	// check_line(corewar, parse, i, str); 
}

void			instr_arg(t_cw *corewar, t_parse *parser, char *str)
{
	t_ls		*tmp;
	
	tmp = add_node(corewar);
	tmp->label = INSTRUCTION;
	parser->args--;
	ft_strcpy(tmp->token, str);
	count_instr(corewar, tmp, str);
	// char	*str;

	// str = ft_strnew(1);
	// while (corewar->line[(*i)])
	// {
	// 	if (ft_isspace(corewar->line[(*i)]))
	// 		break ;
	// 	if (separators(corewar->line[(*i)]))
	// 		break ;
	// 	// printf("|%c|", corewar->line[(*i)]);
	// 	ft_join_char_free(&str, corewar->line[(*i)]);
	// 	(*i)++;
	// }
	// parser->args--;
	// // printf("%s\n", str);
	// free(str);
}

int				count_bytes(int label)
{
	if (label == 1 || label == 9 || label == 12 || label == 15)
		return 1;
	return 2;
}

void			count_instr(t_cw *corewar, t_ls *tmp, char *str)
{
	if (str[0] == 'r' && ((str[1] >= '0' && str[1] <= '9')
		|| (str[2] >= '0' && str[2] <= '9')))
	{
		corewar->res += 1;
		tmp->label = REGISTER;
	}
	else if (str[0] >= '0' && str[0] <= '9')
	{
		corewar->res += 2;
		tmp->label = INDIRECTION;
	}
	else if (str[0] == '%' && str[1] == ':')
	{
		corewar->res += corewar->dir;
		tmp->label = DIRECT_LABEL;
	}
	else if (str[0] == '%')
	{
		corewar->res += corewar->dir;
		tmp->label = DIRECT;
	}
	else
		wrong_instr(corewar);
}

void			wrong_instr(t_cw *corewar)
{
	ft_printf("It's wrong!!!Attention!\n");
	exit(0);
}
