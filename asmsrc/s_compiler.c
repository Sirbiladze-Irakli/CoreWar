/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_compiler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:39:58 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/07 19:50:32 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			s_compiler(t_cw *corewar, char *av)
{
	t_ls        *list;
	int			out;

	if (!(corewar->in = open(av, O_RDONLY)))
		output("Can't open file\n");
	if (!(out = open(corewar->bytecode, O_CREAT | O_RDWR, 0644)))
		output("Can't create file\n");
	take_tokens(corewar);
	fill_magic_header(corewar, out);
	fill_name(corewar, out);
	fill_null(out);
	champ_size(corewar, out);
	fill_comment(corewar, out);
	fill_null(out);
	list = corewar->tokens->next->next->next->next;
	while (list->head != 1)
	{
		if (list->label > 0 && list->label < 17)
			champ_code(corewar, out, list);
		else if (list->label >= 104 && list->label <= 109)
			define_types(corewar, out, list);
		list = list->next;
	}
}

void            define_types(t_cw *corewar, int out, t_ls *list)
{
	if (list->label == REGISTER)
		write_reg(corewar, out, list);
	else if (list->label == DIRECT)
		write_direct(corewar, out, list);
	else if (list->label == INDIRECTION)
		write_ind(corewar, out, list);
	else if (list->label == DIRECT_LABEL)
		write_dir_lab(corewar, out, list);
	else if (list->label ==INDIRECT_LABEL)
		write_ind_lab(corewar, out, list);
}

void			champ_exec_code_size(t_cw *corewar)
{
	t_ls		*tmp;

	tmp = corewar->tokens->next->next->next->next;
	while (tmp->head != 1)
	{
		if (tmp->label == LABEL)
			tmp->pos = corewar->res;
		else if (tmp->label > 0 && tmp->label < 17)
			instr_len(corewar, tmp);
		else if (tmp->label > 103 && tmp->label < 109)
			arg_len(corewar, tmp);
		tmp = tmp->next;
	}
}

void			instr_len(t_cw *corewar, t_ls *tmp)
{
	tmp->pos = corewar->res;
	corewar->res += codetype(tmp) + 1;
	corewar->dir = dir_size(tmp);
}

void			arg_len(t_cw *corewar, t_ls *tmp)
{
	tmp->pos = corewar->res;
	if (tmp->label == REGISTER)
		corewar->res += 1;
	else if (tmp->label == DIRECT || tmp->label == DIRECT_LABEL)
		corewar->res += corewar->dir;
	else if (tmp->label == INDIRECTION || tmp->label == INDIRECT_LABEL)
		corewar->res += 2;
}
