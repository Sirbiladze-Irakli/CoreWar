/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:18:18 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:28:02 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *ret;

	ret = dest;
	while (*dest)
		dest++;
	while (n--)
	{
		if (!(*dest++ = *src++))
			return (ret);
	}
	*dest = '\0';
	return (ret);
}
