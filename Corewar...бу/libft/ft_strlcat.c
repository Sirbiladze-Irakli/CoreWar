/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:51:18 by cdubuque          #+#    #+#             */
/*   Updated: 2019/03/09 18:17:34 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *d, const char *s, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		c;

	i = 0;
	j = 0;
	if (n == 0)
		return (ft_strlen(s));
	while (d[j] != '\0')
		j++;
	if (n > ft_strlen(d))
		c = ft_strlen(s) + ft_strlen(d);
	else
		c = n + ft_strlen(s);
	while (j < n - 1 && s[i] != '\0')
		d[j++] = s[i++];
	d[j++] = '\0';
	return (c);
}
