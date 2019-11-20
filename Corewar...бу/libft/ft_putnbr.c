/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 20:48:08 by cdubuque          #+#    #+#             */
/*   Updated: 2019/08/15 14:35:44 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_null(int *n, int *i)
{
	while (*n >= 10 && *n % *i == 0)
	{
		write(1, &"0", 1);
		*n /= 10;
		*i /= 10;
	}
}

static void			ft_min(int n, int i, char c)
{
	n = -(n + 1);
	while (i != 1 || n > 10)
	{
		c = (n / i) + '0';
		write(1, &(c), 1);
		n = n - (n / i) * i;
		i /= 10;
	}
	write(1, "8", 1);
}

static int			icol(int n)
{
	int				i;

	i = 1;
	while (n / i >= 10 || n / i <= -10)
		i *= 10;
	return (i);
}

static void			vyvod(int n, int i, char c)
{
	while (i != 0 || n > 10)
	{
		c = (n / i) + '0';
		write(1, &c, 1);
		if (n >= 10 && n % i == 0)
			ft_null(&n, &i);
		n = n - (n / i) * i;
		i /= 10;
	}
}

void				ft_putnbr(int n)
{
	int				i;
	char			c;

	i = icol(n);
	c = 0;
	if (n > 2147483647)
		return ;
	if (n < 0)
	{
		write(1, &"-", 1);
		if (n == -2147483648)
			return (ft_min(n, i, c));
		else
			n = -n;
	}
	vyvod(n, i, c);
}
