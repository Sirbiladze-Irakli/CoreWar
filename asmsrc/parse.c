/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:02:16 by jormond-          #+#    #+#             */
/*   Updated: 2019/12/11 19:20:08 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			parse(t_cw *corewar)
{
	int		i;

	i = 0;
	while (corewar->line[i])
	{
		if (ft_isspace(corewar->line[i]))
			skip_spaces(corewar, &i);
		else if (corewar->line[i] == '.')
			dot_label(corewar, &i);
		else if (corewar->line[i] == '"')
			token_in_quotes(corewar, &i);
		else if (corewar->line[i] == ';' || corewar->line[i] == '#')
			while (corewar->line[i] && corewar->line[i] != '\n')
				i++;
		else
			add_token(corewar, &i);
	}
	define_labels(corewar);
//	while (TOKEN)
//	{
//		printf("%p\n", TOKEN);
//		printf("%s\n", TOKEN->token);
//		printf("%d\n\n", TOKEN->label);
//		TOKEN = TOKEN->next;
//	}
}

// void			add_token(t_cw *corewar, int *i)
// {
// 	int		j;

// 	j = -1;
// 	add_node(corewar);
// 	if (corewar->line[(*i)] == '"')
// 		token_in_quotes(corewar, i);
// 	else
// 	{
// 		while (corewar->line[(*i)] && !(ft_isspace(corewar->line[(*i)])))
// 		{
// 			// if (corewar->name == 1 || corewar->comment == 1)
// 			// 	fill_name_and_comment(corewar, i);
// 			TOKEN->token[++j] = corewar->line[(*i)];
// 			corewar->esym++;
// 			(*i)++;
// 			printf("%c\n", TOKEN->token[j]);
// 			if (corewar->line[(*i)] == '"')
// 				break ;
// 		}
// 	}
// 	// printf("|%s|\n", TOKEN->token);
// 	if (ft_strstr(TOKEN->token, ".name") && corewar->name != 1000)
// 		corewar->name++;
// 	else if (ft_strstr(TOKEN->token, ".comment") && corewar->comment != 1000)
// 		corewar->comment++;
// 	if (corewar->name > 1 || corewar->comment > 1)
// 		errors(corewar, 1);
// 	printf("-------------\n");
// }
