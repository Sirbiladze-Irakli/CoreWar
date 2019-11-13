/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormond- <jormond-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:15:30 by jormond-          #+#    #+#             */
/*   Updated: 2019/11/13 19:08:55 by jormond-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	OP_H
# define OP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "op.h"
# include "../libft/includes/libft.h"

typedef struct	s_cw
{
	char		*line;
	char		*output_file;
	int			ret;
}				t_cw;


/*
** main.c
*/

void			init_struct(t_cw *corewar);
void			output(char *str);

/*
** arg_reader.c
*/

void			s_reader(t_cw *corewar, char *av);
void			valid_arg(t_cw *corewar, char *av);
void			cor_reader(t_cw *corewar, char *av);

/*
** tools.c
*/

void			ft_getchar(t_cw *corewar, char *av);
char			*ft_gets(char *buf);

#endif