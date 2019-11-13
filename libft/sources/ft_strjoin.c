/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:17:41 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/10 11:09:27 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	char	*dest;

	dest = NULL;
	if (s1 && s2)
	{
		n = ft_strlen(s1) + ft_strlen(s2);
		dest = (char *)malloc(n + 1);
		if (dest)
		{
			ft_strcpy(dest, (char *)s1);
			ft_strcat(dest, s2);
		}
	}
	return (dest);
}
