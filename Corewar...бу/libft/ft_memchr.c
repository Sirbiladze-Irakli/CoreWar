/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:38:37 by cdubuque          #+#    #+#             */
/*   Updated: 2019/01/24 16:44:27 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char			a;
	const unsigned char		*s1;

	a = c;
	s1 = s;
	while (n--)
	{
		if (*s1 == a)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
