/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:55:02 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/05 20:27:50 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"

static size_t		ft_uintlen(long long n)
{
	size_t			size;

	size = 0;
	while (n >= 10 ? n /= 10 : 0)
		++size;
	return (++size);
}

char				*ft_itoa(long long n)
{
	char			*str;
	long long		un;
	long long		i;
	size_t			size;

	un = n < 0 ? (long long)(n * -1) : (long long)n;
	size = ft_uintlen(un);
	if ((str = ft_strnew(size + (n < 0 ? 1 : 0))))
	{
		n < 0 && (str[0] = '-') ? (++size) : 0;
		i = (int)(size - 1);
		while (un > 9)
		{
			str[i--] = (char)(un % 10 + '0');
			un /= 10;
		}
		str[i] = (char)(un % 10 + '0');
		str[size] = '\0';
	}
	return (str);
}
