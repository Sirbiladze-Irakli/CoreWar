/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_compiler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:39:58 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/22 15:09:53 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			s_compiler(t_cw *corewar, char *av)
{
	unsigned char	*file;
	int				out;

	if (!(corewar->in = open(av, O_RDONLY)))
		output("Can't open file\n");
	if (!(out = open(corewar->bytecode, O_CREAT | O_RDWR, 0644)))
		output("Can't create file\n");
	take_tokens(corewar);
	fill_magic_header(corewar, out);
	fill_name(corewar, out);
	fill_null(out);
	champ_size(corewar, out);
}
