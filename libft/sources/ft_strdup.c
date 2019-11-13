/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:15:52 by jormond-          #+#    #+#             */
/*   Updated: 2019/09/05 19:50:52 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;

	if (!(copy = (char *)malloc(ft_strlen(str) + 1)))
		return (NULL);
	ft_strcpy(copy, (char *)str);
	return (copy);
}
