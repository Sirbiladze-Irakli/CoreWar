/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_magic_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:27:05 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/22 16:20:50 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			fill_magic_header(t_cw *corewar, int out)
{
	unsigned char	tmp[4];
	int				size;
	int8_t			i;

	size = 4;
	i = 0;
	while (size)
	{
		tmp[size - 1] = (uint8_t)((COREWAR_EXEC_MAGIC >> i));
		i += 8;
		size--;
	}
	write(out, tmp, sizeof(tmp));
}

void            fill_name(t_cw *corewar, int out)
{
	t_ls            *list;
	unsigned char   tmp[PROG_NAME_LENGTH];
	int             size;

	size = 0;
	list = TOKEN;
	while (list)
	{
		if (ft_strcmp(list->token, ".name"))
			break ;
		list = list->next;
	}
	while (size < PROG_NAME_LENGTH)
	{
		if (size < ft_strlen(list->token))
			tmp[size] = (uint8_t)((list->token[size]));
		else
			tmp[size] = '\0';
		size++;
	}
	write(out, tmp, PROG_NAME_LENGTH);
}

void            fill_null(int out)
{
	unsigned char   tmp[4];
	int             size;a

	size = 0;
	while (size < 4)
		tmp[size++] = '\0';
	write(out, tmp, 4);
}

void            champ_size(t_cw *corewar, int out)
{
	char            tmp[4];

	corewar->res = 512;
	tmp[3] = corewar->res & 255;
	tmp[2] = (corewar->res & 65280) >> 8;
	tmp[1] = (corewar->res & 16711680) >> 16;
	tmp[0] = (corewar->res & 4278190080) >> 24;
	write(out, tmp, 4);
}