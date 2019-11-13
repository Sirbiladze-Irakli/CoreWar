/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:12:28 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:26:54 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	const char	*ls;
	char		*ld;

	s = src;
	d = dest;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		ls = s + (n - 1);
		ld = d + (n - 1);
		while (n--)
			*ld-- = *ls--;
	}
	return (dest);
}
