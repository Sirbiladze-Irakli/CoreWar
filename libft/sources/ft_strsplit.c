/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:19:30 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/01 16:51:15 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/libft.h"

static size_t		ft_count_word(char *s, char c)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			k++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (k);
}

static char			**ft_split(char **split, char *s, char c, size_t j)
{
	size_t		i;
	size_t		start;
	size_t		k;

	i = 0;
	start = 0;
	k = 0;
	while (s[i] != '\0' && k < j)
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			split[k] = ft_strsub(s, start, i - start);
			k++;
		}
		else
			i++;
	}
	split[k] = NULL;
	return (split);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**split;
	size_t		k;

	if (!s)
		return (NULL);
	k = ft_count_word((char*)s, c);
	split = NULL;
	if ((split = (char**)malloc((k + 1) * sizeof(char*))) == NULL)
		return (NULL);
	split = ft_split(split, (char*)s, c, k);
	return (split);
}
