/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_compiler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:39:58 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/21 19:42:23 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			s_compiler(t_cw *corewar, char *av)
{
	unsigned char	*file;
	int				out;

	if (!(corewar->in = open(av, O_RDONLY)))
		output("Can't open file\n");
	if (!(out = open(corewar->output_file, O_CREAT | O_RDWR, 0644)))
		output("Can't create file\n");
	fill_magic_header(corewar, out);
	// while (get_next_line(corewar->in, &corewar->line))
	take_tokens(corewar);
}
