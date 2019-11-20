/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:13:20 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/09 19:13:51 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*mas(char const *s, char c, size_t *m)
{
	int					i;
	int					col1;
	int					col2;
	char				*ar;

	i = 0;
	col1 = 0;
	col2 = 0;
	if (s[col1] == '\0')
		return (NULL);
	else
	{
		while (s[col1] == c && s[col1] != '\0')
			col1++;
		col2 = col1;
		while (s[col2] != c && s[col2] != '\0')
			col2++;
		if (!(ar = (char *)malloc(sizeof(char) * col2 - col1 + 1)))
			return (NULL);
		while (col1 < col2)
			ar[i++] = s[col1++];
		ar[i] = '\0';
		*m += col2;
	}
	return (ar);
}

static size_t			colvo(char const *s, char c)
{
	size_t			i;
	size_t			k;

	i = 0;
	k = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
		{
			i++;
			if (s[i] == '\0')
				return (k);
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		k++;
	}
	return (k);
}

char					**ft_strsplit(char const *s, char c)
{
	size_t			i;
	size_t			col;
	char			**ar;
	size_t			n;

	n = 0;
	i = 0;
	col = colvo(s, c);
	if (s == NULL || !(ar = (char **)malloc(sizeof(char*) * (col + 1))))
		return (NULL);
	while (i < col)
	{
		ar[i] = mas(&s[n], c, &n);
		if (ar[i] == 0)
		{
			while (i)
				free(ar[--i]);
			free(ar);
			return (NULL);
		}
		i++;
	}
	ar[i] = NULL;
	return (ar);
}
