/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 17:26:01 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/01 06:40:15 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_free_sub(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	unsigned int	col;
	size_t			i;
	char			*ss;

	ss = (char *)s;
	col = 0;
	i = 0;
	if (s == NULL)
		return ("0");
	while (s[col] != '\0')
		col++;
	if (!(s1 = (char *)malloc(sizeof(char) * len + 1)) || (start + len > col))
		return (NULL);
	while (i < len)
		s1[i++] = s[start++];
	s1[i] = '\0';
	free(ss);
	return (s1);
}
