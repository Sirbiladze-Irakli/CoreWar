/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:11:44 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:26:32 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *d;
	char *s;

	d = (char *)dest;
	s = (char *)src;
	if (n)
	{
		while (n--)
		{
			if ((*d++ = *s++) == (char)c)
				return (d);
		}
	}
	return (NULL);
}
