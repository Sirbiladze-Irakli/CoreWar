/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_free_join.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:27:37 by cdubuque          #+#    #+#             */
/*   Updated: 2019/10/09 22:20:51 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_first_free_join(char **s, char *p)
{
	char	*tmp;

	tmp = ft_strjoin(*s, p);
	free(*s);
	*s = tmp;
}
