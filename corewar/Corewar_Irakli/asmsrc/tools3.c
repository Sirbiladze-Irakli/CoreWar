/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:57:29 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/08 20:01:58 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				wtf(t_ls *list)
{
	if (list->label == DIRECT)
	{
		if (list->token[1] == '-')
			return (1);
		else
			return (0);
	}
	else
	{
		if (list->token[0] == '-')
			return (0);
		else
			return (-1);
	}
	return (0);
}
