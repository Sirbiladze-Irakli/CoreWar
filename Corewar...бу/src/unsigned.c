/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:14:37 by cdubuque          #+#    #+#             */
/*   Updated: 2019/11/14 15:52:01 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int				ft_colvo_uns(unsigned long long n, int col, int i)
{
	while ((n / (unsigned)i) > 0)
	{
		col++;
		n /= i;
	}
	return (col);
}

char			*ft_while_uns(unsigned long long n, char *s, int h)
{
	if (n > 9)
		s[h++] = 64 + (n - 9);
	else
		s[h++] = n + '0';
	s[h] = '\0';
	return (s);
}

char			*ft_putt_uns(unsigned long long n, char *s, int i)
{
	long		b;
	int			h;

	b = 1;
	h = 0;
	while (n / b >= i)
		b *= i;
	while (n >= i)
	{
		if (n / b > 9)
			s[h++] = 64 + ((n / b) - 9);
		else
			s[h++] = (n / b) + '0';
		while (n % b < i && n >= i * i)
		{
			s[h++] = '0';
			b /= i;
			n = n / i + n % i;
		}
		n = n - (n / b) * b;
		b /= i;
	}
	return (ft_while_uns(n, s, h));
}

char			*ft_unsigned(unsigned long long n, int i)
{
	char		*s;
	int			col;

	col = 1;
	col = ft_colvo_uns(n, col, i);
	s = ft_strnew(col);
	s = ft_putt_uns(n, s, i);
	return (s);
}
