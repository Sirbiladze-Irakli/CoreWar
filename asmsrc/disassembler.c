#include "asm.h"

void            disassembler(t_cw *corewar, char *av)
{
	int         fd;
	int         out;
	int         res;
	long        pos;
	char        buf[1];
	int         b;
	char        mas;

	b = -1;
	res = 0;
	fd = open(av, O_RDONLY);
	printf("!\n");
	if (!(out = open(corewar->bytecode, O_CREAT | O_RDWR, 0644)))
		output("Can't create file\n");
	printf("!\n");
	pos = lseek(fd, 0L, SEEK_END);
//	if (!(mas = (char *)malloc(sizeof(char) * (pos + 1))))
//		exit(0);
//	ft_bzero(mas, pos + 1);
//	mas[pos] = 22222222;
	pos = lseek(fd, 0L, SEEK_SET);
	while (read(fd, buf, 1) != 0)
	{
		res = (int)buf[0];
		printf("%i - ", res);
		mas = res;
		printf("%c\n", mas);
	}
//	write(out, mas, ft_strlen(mas));
}