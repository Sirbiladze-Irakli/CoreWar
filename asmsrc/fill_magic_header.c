/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_magic_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:27:05 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/20 18:19:44 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			fill_magic_header(t_cw *corewar, int out)
{
	unsigned char	tmp[4] = {0};
	int				size = 4;
	uint8_t			i = 0;

	while(size)
	{
		tmp[size - 1] = (uint8_t)((COREWAR_EXEC_MAGIC >> i));
		i += 8;
		size--;
	}
	write(out, tmp, sizeof(tmp));
}