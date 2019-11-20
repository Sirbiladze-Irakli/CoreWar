/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:37:09 by cdubuque          #+#    #+#             */
/*   Updated: 2019/01/23 18:11:04 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((p1[i] != '\0' || p2[i] != '\0' || i < n - 1) && p1[i] == p2[i])
	{
		i++;
		if ((p1[i] == '\0' && p2[i] == '\0') || i == n)
			return (0);
	}
	return (p1[i] - p2[i]);
}
