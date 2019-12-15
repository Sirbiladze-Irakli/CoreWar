/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:02:18 by jormond-          #+#    #+#             */
/*   Updated: 2019/12/15 15:37:26 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

int         main(int ac, char **av)
{
    int     res = 0;

    res = res | 64;
	printf("%i res\n", res);
    res = res | 32;
	printf("%i res\n", res);
	res = res | 8;
	printf("%i res\n", res);
}
