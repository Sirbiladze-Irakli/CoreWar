/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:31:49 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/09 17:31:58 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *d, const char *s)
{
	int			i;
	size_t		j;

	i = -1;
	j = ft_strlen(d);
	while (s[++i])
		d[j + i] = s[i];
	d[j + i] = '\0';
	return (d);
}
