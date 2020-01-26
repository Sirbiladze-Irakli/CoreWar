/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_char_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:25:59 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/24 17:49:57 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_join_char_free(char **content, char c)
{
	char	*tmp;
	char	chr[2];

	ft_bzero(chr, 2);
	chr[0] = c;
	tmp = ft_strjoin(*content, chr);
	free(*content);
	*content = tmp;
}