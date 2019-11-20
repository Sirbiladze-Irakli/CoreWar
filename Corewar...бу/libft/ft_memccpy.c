/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 19:21:38 by cdubuque          #+#    #+#             */
/*   Updated: 2019/01/21 17:25:34 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0 && *(unsigned const char *)src != (unsigned char)c)
	{
		n--;
		*(unsigned char *)dst++ = *(unsigned const char *)src++;
	}
	if (n > 0)
	{
		*(unsigned char *)dst++ = *(unsigned const char *)src++;
		return (dst);
	}
	else
		return (NULL);
}
