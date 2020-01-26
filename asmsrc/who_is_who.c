/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   who_is_who.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:22:00 by jormond-          #+#    #+#             */
/*   Updated: 2020/01/26 17:52:42 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            who_is_who(t_cw *corewar, t_parse *parser, int *i)
{
	char        *str;
	char		*tmp;

	str = ft_strnew(1);
	while (corewar->line[(*i)])
	{
		if (ft_isspace(corewar->line[(*i)]) || separators(corewar->line[(*i)]))
		{
			tmp = ft_strtrim(str);
			free(str);
			str = tmp;
			define_str(corewar, parser, i, str);
			free(str);
			return ;
		}
		ft_join_char_free(&str, corewar->line[(*i)]);
		corewar->esym++;
		(*i)++;
	}
	free(str);
	return ;
}

void			define_str(t_cw *corewar, t_parse *parser, int *i, char *str)
{
	t_ls		*tmp;
	
	tmp = corewar->tokens;
	if (tab(str))
		process_instr(corewar, parser, i, str);
	else if (str[ft_strlen(str) - 1] == ':')
	{
		tmp = add_node(corewar);
		tmp->label = LABEL;
		ft_strcpy(tmp->token, str);
	}
	else
		return ;         // write func for errors processing
}

int				tab(char *str)
{
	int			i;

	i = 0;
	while (++i < 17)
		if (!ft_strcmp(op_tab[i].instr, str))
			return i;
	return 0;
}
