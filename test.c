/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:02:18 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/04 18:17:47 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <regex.h>
# include "inc/asm.h"

int         	main(int ac, char **av)
{
	int			res;

    res = parser("%34345tsf", T_DIR_PATTERN);
	printf("%d res \n", res);
	return (0);
}

int			parser(char *str, char *pattern)
{
	int			error;
	regex_t		reg;
	regmatch_t	pm;

	error = regcomp(&reg, pattern, REG_EXTENDED);
	printf("%d error\n", error);
	if (!regexec(&reg, str, 0, &pm, 0))
		return (0);
	return (1);
}
