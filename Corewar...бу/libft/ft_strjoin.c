/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:22:43 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/09 19:05:14 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*s;
	size_t		col1;
	size_t		col2;
	int			i;

	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	col1 = ft_strlen(s1);
	col2 = ft_strlen(s2);
	if (!(s = (char *)malloc(sizeof(char) * (col1 + col2 + 1))))
		return (NULL);
	while (col1--)
		s[++i] = *s1++;
	while (col2--)
		s[++i] = *s2++;
	s[++i] = '\0';
	return (s);
}
