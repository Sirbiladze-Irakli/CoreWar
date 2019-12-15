#include "asm.h"

void            champ_code(t_cw *corewar, int out, t_ls *list)
{
	t_ls        *tmp;
	uint8_t     type;
	char        c;

	tmp = list;
	type = 0;
	c = tmp->label;
	corewar->dir = dir_size(tmp);
	write(out, &c, 1);
	if (tmp->label != LIVE && tmp->label != ZJMP && tmp->label != FORK
	&& tmp->label != LFORK)
	{
		define_types(corewar, tmp, &type);
		c = type;
		write(out, &c, 1);
	}
	how_many_args(corewar, tmp);
//	while ()
//	{
//	}
}

void            define_types(t_cw *corewar, t_ls *tmp, uint8_t *type)
{
	ITER = 0;
	how_many_args(corewar, tmp);
	while (COUNTER--)
	{
		tmp = tmp->next;
		if (ft_strchr(tmp->token, 'r'))
			reg_fill(corewar, type);
		else if (ft_strchr(tmp->token, '%'))
			dir_fill(corewar, type);
		else
			ind_fill(corewar, type);
		ITER++;
	}
}

void            reg_fill(t_cw *corewar, uint8_t *type)
{
	if (ITER == 0)
		(*type) |= 64;
	else if (ITER == 1)
		(*type) |= 16;
	else if (ITER == 2)
		(*type) |= 4;
}

void            dir_fill(t_cw *corewar, uint8_t *type)
{
	if (ITER == 0)
		(*type) |= 128;
	else if (ITER == 1)
		(*type) |= 32;
	else if (ITER == 2)
		(*type) |= 8;
}

void            ind_fill(t_cw *corewar, uint8_t *type)
{
	if (ITER == 0)
		(*type) |= 192;
	else if (ITER == 1)
		(*type) |= 48;
	else if (ITER == 2)
		(*type) |= 12;
}