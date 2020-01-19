/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_char_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:25:59 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/19 19:29:57 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_join_char_free(char **content, char c)
{
	char	*tmp;

	printf("!\n");
	tmp = ft_charjoin(*content, c);
	free(*content);
	*content = tmp;
}