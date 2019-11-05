#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int main()
{
	char src[] = "abcd";
	char dest[] = "01234";

	printf("%s\n", ft_strcat(dest, src));
}
