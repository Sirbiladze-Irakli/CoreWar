/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwilderm <hwilderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:11:54 by jormond-          #+#    #+#             */
/*   Updated: 2019/08/24 18:26:35 by hwilderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	char *arr1;

	arr1 = (char *)arr;
	if (n != 0)
	{
		while (n--)
		{
			if (*arr1 == (char)c)
				return ((void *)arr1);
			arr1++;
		}
	}
	return (NULL);
}
