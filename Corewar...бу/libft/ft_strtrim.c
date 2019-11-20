/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 18:49:28 by cdubuque          #+#    #+#             */
/*   Updated: 2019/01/30 21:44:36 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		c;
	char		*str;

	i = 0;
	j = 0;
	c = 0;
	if (s == NULL)
		return (NULL);
	while (s[c] != '\0')
		c++;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[c - 1] == ' ' || s[c - 1] == '\n' || s[c - 1] == '\t')
		c--;
	if (c < i)
		c = i;
	if (!(str = (char *)malloc(sizeof(char) * (c - i + 1))))
		return (NULL);
	while (i < c)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
