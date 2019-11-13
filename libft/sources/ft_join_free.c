/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rage <rage@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:46:54 by jormond-          #+#    #+#             */
/*   Updated: 2019/10/13 21:13:47 by rage             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_join_free(char **content, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*content, buf);
	free(*content);
	*content = tmp;
}
