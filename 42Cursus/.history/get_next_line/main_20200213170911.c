#include "get_next_line.h"
int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	//int		ret;

	i = 0;
	(void)argc;
	(void)argv;
	fd = open(("prueba.txt"), O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		printf("15 free %p\n", line);
		//ret = get_next_line(fd, &line);
		free(line);
		i++;
	}
	printf("20 free %p\n", line);
	free(line);
	getchar();
}