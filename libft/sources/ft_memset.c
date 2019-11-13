/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:12:37 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/01 19:43:00 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *arr, int c, size_t n)
{
	char *arr1;

	if (n == 0)
		return (arr);
	arr1 = (char *)arr;
	while (n--)
		*arr1++ = (char)c;
	return (arr);
}