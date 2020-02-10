/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 17:14:37 by cdubuque          #+#    #+#             */
/*   Updated: 2020/02/10 18:33:41 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

size_t			ft_colvo_uns(unsigned long long n, size_t col, size_t i)
{
	while ((n / (unsigned)i) > 0)
	{
		col++;
		n /= i;
	}
	return (col);
}

char			*ft_while_uns(unsigned long long n, char *s, int h, size_t m)
{
	if (n > 9)
		s[h++] = 64 + m + (n - 9);
	else
		s[h++] = n + '0';
	s[h] = '\0';
	return (s);
}

char			*ft_putt_uns(unsigned long long n, char *s, size_t i, size_t m)
{
	size_t		b;
	int			h;

	b = 1;
	h = 0;
	while (n / b >= i)
		b *= i;
	while (n >= i)
	{
		if (n / b > 9)
			s[h++] = 64 + m + ((n / b) - 9);
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
	return (ft_while_uns(n, s, h, m));
}

char			*ft_unsigned(unsigned long long n, size_t i, size_t m)
{
	char		*s;
	size_t		col;

	col = 1;
	col = ft_colvo_uns(n, col, i);
	s = ft_strnew(col);
	s = ft_putt_uns(n, s, i, m);
	return (s);
}
