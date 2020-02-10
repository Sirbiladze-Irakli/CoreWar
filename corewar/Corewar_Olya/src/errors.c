/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:41:50 by cdubuque          #+#    #+#             */
/*   Updated: 2020/01/30 13:01:10 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		error(char *s)
{
	write(2, s, ft_strlen(s));
	exit(0);
}

void		ft_true_header(char *mh, char *mh2, char *fullname)
{
	char	*s;

	if (ft_strcmp(mh, mh2))
	{
		s = ft_strdup("Error: File ");
		ft_first_free_join(&s, fullname);
		ft_first_free_join(&s, " has an invalid header\n");
		error(s);
	}
}

void		ft_code_size(t_player **players, int *mas, int i, int pos)
{
	char	*s;

	players[i]->code_size = ((unsigned char)(mas[pos]) << 24) | \
	((unsigned char)(mas[pos + 1]) << 16) | \
	((unsigned char)(mas[pos + 2]) << 8) | (unsigned char)(mas[pos + 3]);
	if (players[i]->code_size > CHAMP_MAX_SIZE)
	{
		s = ft_strdup("Error: File ");
		ft_first_free_join(&s, players[i]->fullname);
		ft_first_free_join(&s, " has too large a code (");
		ft_first_free_join(&s, ft_itoa(players[i]->code_size));
		ft_first_free_join(&s, " bytes > ");
		ft_first_free_join(&s, ft_itoa(CHAMP_MAX_SIZE));
		ft_first_free_join(&s, " bytes)\n");
		error(s);
	}
}
