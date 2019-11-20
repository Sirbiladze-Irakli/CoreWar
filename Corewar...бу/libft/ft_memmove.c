/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:39:28 by cdubuque          #+#    #+#             */
/*   Updated: 2019/01/22 13:58:49 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t n)
{
	size_t	i;

	i = 0;
	if ((int)((const char *)s - (char *)d) > 0)
	{
		while (i < n)
		{
			*((char *)d + i) = *((const char *)s + i);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			*((char *)d + n - 1 - i) = *((const char *)s + n - 1 - i);
			i++;
		}
	}
	return (d);
}
