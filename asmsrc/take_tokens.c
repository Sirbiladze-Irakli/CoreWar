/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:25:36 by jormond-          #+#    #+#             */
/*   Updated: 2019/12/11 19:33:20 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void            take_tokens(t_cw *corewar)
{
	read_line(corewar->in, &corewar->line);
	parse(corewar);
	return ;
}

void            parse_tokens(t_cw *corewar)
{
	corewar->eline++;
	name_and_comment(corewar);
	errors(corewar, 0, 0);
}

void            name_and_comment(t_cw *corewar)
{
	if (ft_strstr(corewar->line, ".name"))
		read_name(corewar);
	if (ft_strstr(corewar->line, ".comment"))
	{
		corewar->comment++;
		// name_and_comment_reader(corewar, 2);
	}
	corewar->esym = 0;
	// if (corewar->name > 1 || corewar->comment > 1)
		// error_out(corewar, 1, "\0");
}

void			fill_name_and_comment(t_cw *corewar, int *i)
{
	if (corewar->line[(*i)] != '"')
		errors(corewar, 2, 0);
}

void			token_in_quotes(t_cw *corewar, int *i)
{
	int		j;
	int		ssym;
	int		sline;

	j = -1;
	ssym = corewar->esym;
	sline = corewar->eline;
	printf("!\n");
	while (corewar->line[++(*i)] && corewar->line[(*i)] != '"')
	{
		printf("!\n");
		TOKEN->token[++j] = corewar->line[(*i)];
		corewar->esym++;
		if (corewar->line[(*i)] == '\n')
		{
			corewar->esym = 1;
			corewar->eline++;
		}
	}
	// if (!(ft_strchr(TOKEN->token, '\n')))
	// 	errors()
}

/*
** The function under this line don't allocate memory for new list. Fix it!
*/

void				dot_label(t_cw *corewar, int *i) 
{
	t_ls		*tmp;
	int			j;

	j = -1;
	tmp = add_node(corewar);
	while(!(separators(corewar->line[(*i)])) && !(ft_isspace(corewar->line[(*i)])))
	{
		tmp->token[++j] = corewar->line[(*i)++];
		corewar->esym++;
	}
	printf("%d = i\n", (*i));
	// printf("%s\n", TOKEN->token);
	if (!(ft_strcmp(tmp->token, ".name")))
		corewar->name++;
	if (!(ft_strcmp(tmp->token, ".comment")))
		corewar->comment++;
	if (corewar->name > 1 || corewar->comment > 1)
		errors(corewar, 1, corewar->esym);
	if (corewar->name != 1 && corewar->comment != 1)
		errors(corewar, 1, corewar->esym);
}
