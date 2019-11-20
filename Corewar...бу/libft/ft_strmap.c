/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:20:36 by cdubuque          #+#    #+#             */
/*   Updated: 2019/01/22 14:43:38 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*s1;
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	while (s[count] != '\0')
		count++;
	if (!(s1 = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		s1[i] = f(s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
