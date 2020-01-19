/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:27:32 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/19 19:13:18 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	    *ft_charjoin(char const *s1, char const c)
{
	char	*dest;
    int     i;

    i = ft_strlen(s1);
	dest = NULL;
	if (s1)
	{
		dest = (char *)malloc(1);
		if (dest)
		{
			ft_strcpy(dest, (char *)s1);
			dest[i] = c;
		}
	}
	return (dest);
}