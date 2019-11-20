/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:40:23 by cdubuque          #+#    #+#             */
/*   Updated: 2018/12/15 17:07:37 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	char		*dd;
	size_t		i;

	dd = (char *)dest;
	i = 0;
	while (i < n)
		dd[i++] = c;
	return ((void *)dd);
}
