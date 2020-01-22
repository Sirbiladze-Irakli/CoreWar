/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:51:19 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/22 18:24:21 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void            error_vars(t_cw *corewar, char *str, int flag)
{
    if (flag == LABEL)
    ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
LABEL \"%s\"\n", corewar->eline, corewar->esym, str);
    
}