/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:18:10 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:27:59 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fresh;
	unsigned int	i;
	unsigned int	j;

	if (!s || !f)
		return (NULL);
	i = ft_strlen(s);
	if (!(fresh = (char *)malloc(i + 1)))
		return (NULL);
	j = 0;
	while (j < i)
	{
		fresh[j] = f(j, s[j]);
		j++;
	}
	fresh[j] = '\0';
	return (fresh);
}
