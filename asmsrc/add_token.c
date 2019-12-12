/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:11:08 by jormond-          #+#    #+#             */
/*   Updated: 2019/12/12 15:11:12 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            add_token(t_cw *corewar, int *i)
{
    int       j;
    t_ls      *tmp;

    j = -1;
    tmp = add_node(corewar);
    while (!(separators(corewar->line[(*i)])) && !(ft_isspace(corewar->line[(*i)])))
    {

    }
}