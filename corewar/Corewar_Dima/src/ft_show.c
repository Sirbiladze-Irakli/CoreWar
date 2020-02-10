#include "op.h"


void	ft_show(t_player **players, t_corewar *corewar, t_carriage ***carriage)
{
    int c;
    int y, x, yBeg, xBeg, yMax, xMax;
    WINDOW *win;
    WINDOW *win2;
    int k = 2;
    // int *map;

    initscr();
    noecho();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);

    init_pair(6, COLOR_BLACK, COLOR_WHITE);
    init_pair(7, COLOR_BLACK, COLOR_CYAN);
    init_pair(8, COLOR_BLACK, COLOR_RED);
    init_pair(9, COLOR_BLACK, COLOR_GREEN);
    init_pair(10, COLOR_BLACK, COLOR_MAGENTA);
    


    char *core[8] = {" ###    ###   ####   #####",
                    "#   #  #   #  #   #  #",
                    "#      #   #  #   #  #",
                    "#      #   #  ####   ####",
                    "#      #   #  # #    #",
                    "#   #  #   #  #  #   #",
                    " ###    ###   #   #  #####", ""};
    
    char *war[8] = {"#   #   ###   ####",
                    "#   #  #   #  #   #",
                    "#   #  #   #  #   #",
                    "# # #  #####  ####",
                    "# # #  #   #  # #",
                    "# # #  #   #  #  #",
                    " # #   #   #  #   #", ""};
    
    char *to[8] = {" ###     #",
                    "#   #   ##",
                    "#   #  # #",
                    "   #     #",
                    "  #      #",
                    " #       #",
                    "#####   ###", ""};
    
    win = newwin(68, 197, 0, 0);
    win2 = newwin(43, 55, 0, 196);
    
    getyx(stdscr, y, x);
    getbegyx(win, yBeg, xBeg);
    getmaxyx(stdscr, yMax, xMax);
    c = getch();
    wborder(win, 35, 35, 35, 35, 35, 35, 35, 35);
    wborder(win2, 35, 35, 35, 35, 35, 35, 35, 35);
    
    while (k < 10)
    {
        wattron(win2, COLOR_PAIR(2));
        mvwprintw(win2, k, 3, "%s", core[k - 2]);
        mvwprintw(win2, 8 + k, 30, "%s", war[k - 2]);
        wattron(win2, COLOR_PAIR(3));
        mvwprintw(win2, 8 + k, 8, "%s", to[k - 2]);
        wattroff(win2, COLOR_PAIR(3));
        wrefresh(win2);
        // mvwprintw(win, 5, 5 + i * 3, "%.2x ", i);
        // wrefresh(win);
        // usleep(300000);
        k++;
    }
    
    wrefresh(win);
    wrefresh(win2);
    wrefresh(win);
    while (1)
    {
        refresh();
        c = getch();
        wrefresh(win2);
        wrefresh(win);
        
        if (c == 27)
            break ;
    }
    

	int		cycle;
	int 	i;
	// t_op	op_tab[16] =
	// {
	// 	{"live", 1, 1, 10, "alive", 0, 0},
	// 	{"ld", 2, 2, 5, "load", 1, 0},
	// 	{"st", 2, 3, 5, "store", 1, 0},
	// 	{"add", 3, 4, 10, "addition", 1, 0},
	// 	{"sub", 3, 5, 10, "soustraction", 1, 0},
	// 	{"and", 3, 6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	// 	{"or", 3, 7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	// 	{"xor", 3, 8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	// 	{"zjmp", 1, 9, 20, "jump if zero", 0, 1},
	// 	{"ldi", 3, 10, 25, "load index", 1, 1},
	// 	{"sti", 3, 11, 25, "store index", 1, 1},
	// 	{"fork", 1, 12, 800, "fork", 0, 1},
	// 	{"lld", 2, 13, 10, "long load", 1, 0},
	// 	{"lldi", 3, 14, 50, "long load index", 1, 1},
	// 	{"lfork", 1, 15, 1000, "long fork", 0, 1},
	// 	{"aff", 1, 16, 2, "aff", 1, 0},
	// };
	cycle = 0;
    int b;
    int n;
    int m;

    b = -1;
    n = 2;
    m = 3;
    create_map_color(corewar);
    fill_players(players, corewar);
	while (COL_CAR != 0 && (++cycle <= corewar->cycles_to_die || corewar->cycles_to_die < 0) \
	&& ((corewar->start_cycles < corewar->dump && corewar->dump > 0) || corewar->dump < 0))
	{
        ft_print_arena(corewar, carriage, win, win2);	
		corewar->start_cycles++;
		if (corewar->v30 == 1)
			ft_printf("It is now cycle %i\n", corewar->start_cycles);
		while (++CAR < COL_CAR)
		{
			// ft_printf("%d ,", CAR);
			// ft_printf("%d ,", (*carriage)[CAR]->cyc_to_op);
			
			if ((*carriage)[CAR]->cyc_to_op == 0)
				(*carriage)[CAR]->op_code = corewar->arena[(*carriage)[CAR]->PC];
			if ((*carriage)[CAR]->op_code > 0 && (*carriage)[CAR]->op_code < 17)
			{
				if ((*carriage)[CAR]->cyc_to_op == 0)
					(*carriage)[CAR]->cyc_to_op = op_tab[(*carriage)[CAR]->op_code - 1].cycles;
				if ((*carriage)[CAR]->cyc_to_op > 1)
					(*carriage)[CAR]->cyc_to_op--;
				else
					ft_operations(carriage, corewar);
			}
			else
			{
				(*carriage)[CAR]->PC = ft_limit((*carriage)[CAR]->PC + 1);
				(*carriage)[CAR]->arg_types = ft_limit((*carriage)[CAR]->PC + 1);
			}
		}
		if (cycle == corewar->cycles_to_die || corewar->cycles_to_die < 0)
		{
			ft_verification_go(corewar, carriage); 
			cycle = 0;
		}
		CAR = -1;
	}
    endwin();
}

void    ft_print_arena(t_corewar *corewar, t_carriage ***carriage , WINDOW *win, WINDOW *win2)
{
    int		i;
    int     k;
    int     j;
    int     color;

	i = -1;
    j = 2;
    k = 3;
	while (++i < MEM_SIZE)
	{
        color = corewar->color_map[i];
		if (i % 64 == 0 && i >= 64)
        {
            k = 3;
            j++;
        }
        wattron(win, COLOR_PAIR(color));
        mvwprintw(win, j, k, "%.2x", corewar->arena[i]);
        if (ft_check_car(corewar, carriage, win2, i))
        {
            wattron(win, COLOR_PAIR(color + 5));
            mvwprintw(win, j, k, "%.2x", corewar->arena[i]);
            wattroff(win, COLOR_PAIR(color + 5));
        }
        k += 3;
        mvwprintw(win2, 27, 3, "Cycles total : %d", corewar->start_cycles);
        mvwprintw(win2, 28, 3, "Carriages total : %d", corewar->col_car);
        mvwprintw(win2, 29, 3, "cycles_to_die : %d", corewar->cycles_to_die);
	}
    wrefresh(win);
    wrefresh(win2);
}
int    ft_check_car(t_corewar *corewar, t_carriage ***carriage, WINDOW *win2, int i)
{
    int num_car;
    
    num_car = -1;
    while(++num_car != corewar->col_car)
    {
        if ((*carriage)[num_car]->PC == i)
        {
            mvwprintw(win2, 30, 3, "%d", (*carriage)[num_car]->registrs[REG_NUMBER]);
            wrefresh(win2);;
            return (1);
        }
    }
    return(0);
}

void    create_map_color(t_corewar *corewar)
{
    int i;

    i = -1;
    corewar->color_map = (int *)malloc(sizeof(int) * MEM_SIZE);
    while (++i < MEM_SIZE)
        corewar->color_map[i] = 1;
}

void    fill_players(t_player **players, t_corewar *corewar)
{
    int		c;
	int		i;

	c = -1;
	while (++c < COL_PL)
	{
		i = -1;
		while (++i < players[c]->code_size)
			corewar->color_map[players[c]->start + i] = c + 2;
	}
}