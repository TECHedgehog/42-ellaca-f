#include <stddef.h>

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *l;
	int i;

	l = str;
	i = 0;
	while (n > 0)
	{
		l[i] = c;
		i++;
		n--;
	}
	return (str);
}

int main()
{
	printf("%s\n", ft_memset("hola que tal", 48, 4));
}
