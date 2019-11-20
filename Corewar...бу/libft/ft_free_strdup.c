/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strdup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdubuque <cdubuque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 13:58:18 by cdubuque          #+#    #+#             */
/*   Updated: 2019/09/01 06:44:26 by cdubuque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_free_strdup(char *s, size_t i)
{
	char	*tmp;

	tmp = ft_strdup(s + i);
	free(s);
	return (tmp);
}
