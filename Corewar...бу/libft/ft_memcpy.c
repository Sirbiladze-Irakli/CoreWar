/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:43:51 by cdubuque          #+#    #+#             */
/*   Updated: 2018/12/26 21:39:39 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	char		*dd;
	char		*ss;
	size_t		i;

	dd = (char *)d;
	ss = (char *)s;
	i = 0;
	while (i < n)
	{
		dd[i] = ss[i];
		i++;
	}
	if (!dd)
		return (NULL);
	return ((void *)dd);
}
