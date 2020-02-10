/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:33:34 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/09 16:27:40 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				separators(char c)
{
	return ((c == '"' || c == ',' || c == ';' || c == '#'));
}

void			new_line(t_cw *corewar)
{
	corewar->esym = 0;
	corewar->eline++;
}

void			check_comment(t_ls *tmp)
{
	if (ft_strlen(tmp->token) > COMMENT_LENGTH)
	{
		ft_printf("Champion comment too long (Max length %d)\n"
			, COMMENT_LENGTH);
		exit(0);
	}
	tmp->label = COMMENT;
}

void			check_name(t_ls *tmp)
{
	if (ft_strlen(tmp->token) > PROG_NAME_LENGTH)
	{
		ft_printf("Champion name too long (Max length %d)\n"
			, PROG_NAME_LENGTH);
		exit(0);
	}
	tmp->label = NAME;
}

int				substrncmp(char *dest, char *find, int begin, int n)
{
	int			i;

	i = 0;
	if ((ft_strlen(find) - 1) != (size_t)n)
		return (1);
	while (i < n)
		if (dest[begin++] != find[i++])
			return (1);
	return (0);
}
