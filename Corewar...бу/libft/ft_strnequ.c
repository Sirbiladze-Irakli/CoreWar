/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:12:41 by cdubuque          #+#    #+#             */
/*   Updated: 2019/01/17 14:47:37 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		col2(size_t n, char const *s1, char const *s2)
{
	if (n < ft_strlen(s1) && n < ft_strlen(s2))
		return (n);
	else if (ft_strlen(s1) <= ft_strlen(s2))
		return (ft_strlen(s1) + 1);
	else
		return (ft_strlen(s2) + 1);
}

int				ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t			i;
	size_t			j;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n == 0)
		return (1);
	j = col2(n, s1, s2);
	while (i < j)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
