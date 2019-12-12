/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:51:18 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/29 17:16:14 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char        	*ft_itoa_base(int value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

void			name_and_comment_reader(t_cw *corewar, int var)
{
	char	*tmp;

	if (var == 1)
	{
		
	}
	while (corewar->line[corewar->esym])
	{
		if (corewar->line[corewar->esym] == '"')
		{
			return ;
		}
	}
}

void			skip_spaces(t_cw *corewar, int *i)
{
	while (ft_isspace(corewar->line[(*i)]))
	{
		corewar->esym++;
		if (corewar->line[(*i)] == '\n')
		{
			corewar->esym = 1;
			corewar->eline++;
		}
		(*i)++;
	}
}

int				separators(char c)
{
	return ((c == '"' || c == ',' || c == ';' || c == '#'));
}
