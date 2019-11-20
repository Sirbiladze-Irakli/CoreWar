/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_free_join.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:27:37 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/01 05:09:06 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_second_free_join(char *s, char *p)
{
	char	*tmp;

	tmp = ft_strjoin(s, p);
	free(p);
	return (tmp);
}
