/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:38:03 by cdubuque          #+#    #+#             */
/*   Updated: 2019/01/24 17:51:43 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss2 = s2;
	ss1 = s1;
	if (n == 0)
		return (0);
	if (!ss1 && !ss2)
		return (0);
	while (*ss1 == *ss2 && --n)
	{
		ss1++;
		ss2++;
	}
	return (*ss1 - *ss2);
}
