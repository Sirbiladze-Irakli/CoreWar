/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:02:18 by jormond-          #+#    #+#             */
/*   Updated: 2020/02/03 20:22:06 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <regex.h>

int         	main(int ac, char **av)
{
	int			res;

    res = parser("r2234", T_REG_PATTERN);
	return (0);
}

int			parser(char *str, char *pattern)
{
	int			error;
	regex_t		reg;
	regmatch_t	pm;

	error = regcomp(&reg, pattern, REG_EXTENDED);
	if (!regexec(&reg, str, 0, &pm, 0))
		printf("gooood!\n");
	printf("%d\n", error);
	return (0);
}
