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
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		//ret = get_next_line(fd, &line);
		i++;
	}
	printf("%s\n", line);
}