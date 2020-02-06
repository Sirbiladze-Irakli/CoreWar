/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_compiler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:39:58 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/06 20:53:54 by jormond-         ###   ########.fr       */
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
	list = corewar->tokens;
	while (list)
	{
		if (list->label > 0 && list->label < 17)
			champ_code(corewar, out, list);
		else if (list->label >= 104 && list->label <= 109)
			define_types(corewar, list);
		list = list->next;
	}
}

void            define_types(t_cw *corewar, t_ls *tmp)
{
	if (tmp->label == REGISTER)
		write_reg(corewar, tmp);
	else if (tmp->label == DIRECT)
		write_direct(corewar, tmp);
	else if (tmp->label == INDIRECTION)
		write_ind(corewar, tmp);
	else if (tmp->label == DIRECT_LABEL)
		write_dir_lab(corewar, tmp);
	else if (tmp->label ==INDIRECT_LABEL)
		write_ind_lab(corewar, tmp);
}
