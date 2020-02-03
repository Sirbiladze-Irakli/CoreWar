/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorOut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:43:57 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/02 16:21:49 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            ErrorOut(t_cw *corewar, t_parse *parser, int flag)
{
    if (flag == LEXICAL)
        ft_printf("Lexical error at [%d:%d]\n", corewar->eline, corewar->esym);
    else if (flag == NAME_ERROR)
        ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
COMMAND_NAME \".name\"\n", corewar->eline, corewar->esym);
    else if (flag == COMMENT_ERROR)
        ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
COMMAND_COMMENT \".comment\"\n", corewar->eline, corewar->esym);
    else if (flag == END_LINE_ERROR)
        ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
ENDLINE\n", corewar->eline, corewar->esym);
    else if (flag == SEPARATOR_ERROR)
        ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
SEPARATOR \",\"\n", corewar->eline, corewar->esym);
    else if (flag == 406    )
        ft_printf("Syntax error at token [TOKEN][%.3d:%.3d] \
%s\n", corewar->eline, corewar->esym - ft_strlen(corewar->lastarg)
        , corewar->lastarg);
    else if (flag == ARG_NUM_ERROR)
        ft_printf("Invalid parameter count for instruction %s\n",
			corewar->lastinstr);
    exit(0);
}
