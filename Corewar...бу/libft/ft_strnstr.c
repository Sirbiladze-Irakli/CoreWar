/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:14:09 by cdubuque          #+#    #+#             */
/*   Updated: 2019/01/23 17:18:02 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 && n)
	{
		i = n;
		a = (char *)s1;
		b = (char *)s2;
		while (*a == *b && n && *b)
		{
			a++;
			b++;
			n--;
			if (*b == '\0')
				return ((char *)s1);
		}
		s1++;
		n = i - 1;
	}
	return (NULL);
}
