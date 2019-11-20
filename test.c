/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:02:18 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/17 16:42:08 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

int         main(int ac, char **av)
{
    int     out;
    int     i;
    int     pos;
    int     ret;
    char    buf[1];
    
    ret = 0;
    i = 0;
    out = open(av[1], O_RDONLY);
    while ((ret = read(out, buf, 1)) && i++ < 15)
    {
        printf("%c", buf[0]);
    }
    printf("\n");
}