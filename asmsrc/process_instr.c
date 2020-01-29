/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:52:56 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/29 16:07:04 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** функция определяет какая инструкция ей пришла
** и отталкиваясь от шаблона продолжает писать аргументы
** друг за другом в связный список corewar->tokens
*/

void		process_instr(t_cw *corewar, t_parse *parser, char *str)
{
	t_ls	*tmp;
	int		j;

	tmp = add_node(corewar);
	j = tab(str);
	parser->order = j;
	parser->args = op_tab[j].arg_num;
	tmp->label = j;
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

void		instr_arg(t_cw *corewar, t_parse *parser, char *str)
{
	t_ls	*tmp;
	
	tmp = add_node(corewar);
	tmp->label = INSTRUCTION;
	parser->args--;
	ft_strcpy(tmp->token, str);

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