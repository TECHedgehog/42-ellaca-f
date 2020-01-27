#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char    *ft_strnew(size_t size)
{
    char    *str;
    size_t    i;

    i = 0;
    str = NULL;
    str = (char *)malloc(size * sizeof(*str) + 1);
    if (str == NULL)
        return (NULL);
    while (i < size)
    {
        str[i] = '\0';
        i++;
    }
    str[size] = '\0';
    return (str);
}

size_t    ft_strlen(const char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *str;
    size_t    i;

    i = 0;
    if (s1 == NULL || s2 == NULL)
        return (NULL);
    str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (str == NULL)
        return (NULL);
    while (i < ft_strlen(s1))
    {
        str[i] = s1[i];
        i++;
    }
    while (i < ft_strlen(s1) + ft_strlen(s2))
    {
        str[i] = s2[i - ft_strlen(s1)];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *ft_strdup(const char *s1)
{
    char    *s2;
    int        i;

    i = 0;
    s2 = (char *)malloc(sizeof(*s2) * (ft_strlen(s1) + 1));
    if (s2 == NULL)
        return (NULL);
    while (s1[i])
    {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
    return (s2);
}

char    *ft_strsub(char const *s, unsigned int start, size_t len)
{
    size_t    i;
    char    *str;

    i = 0;
    if (s == NULL)
        return (NULL);
    str = (char *)malloc(sizeof(*str) * (len + 1));
    if (str == NULL)
        return (NULL);
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *ft_strchr(const char *s, int c)
{
    int i;

    if ((char)c == '\0')
        return ((char*)s + ft_strlen(s));
    i = 0;
    while (s[i])
    {
        if (s[i] == (char)c)
            return ((char*)s + i);
        i++;
    }
    return (NULL);
}

int    ft_stock2line(char **stock, char **line)
{
    int len;

    if (ft_strchr(*stock, '\n') != NULL)
    {
        len = ft_strchr(*stock, '\n') - *stock;
        line[0] = ft_strsub(*stock, 0, len);
        *stock = ft_strchr(*stock, '\n') + 1;
        return (1);
    }
    line[0] = ft_strdup(*stock);
    *stock = NULL;
    return (0);
}

int    read_f(char **line, const int fd, char **stock, char *str)
{
    char    *tmp;
    int        len;
    int        ret;

    while ((ret = read(fd, str, BUFF_SIZE)))
    {
        if (ret == -1)
            return (ret);
        str[ret] = '\0';
        tmp = ft_strdup(line[0]);
        free(line[0]);
        line[0] = ft_strjoin(tmp, str);
        free(tmp);
        if (ft_strchr(line[0], '\n'))
        {
            len = ft_strchr(line[0], '\n') - line[0];
            *stock = ft_strdup(ft_strchr(line[0], '\n') + 1);
            tmp = ft_strdup(line[0]);
            free(line[0]);
            line[0] = ft_strsub(tmp, 0, len);
            free(tmp);
            break ;
        }
    }
    return (ret);
}

int    get_next_line(const int fd, char **line)
{
    int            ret;
    static char    *stock = NULL;
    char        *str;

    if (line == NULL || fd < 0 || BUFF_SIZE < 1)
        return (-1);
    line[0] = ft_strnew(BUFF_SIZE);
    if (stock != NULL)
        if (ft_stock2line(&stock, &line[0]))
            return (1);
    str = ft_strnew(BUFF_SIZE);
    if ((ret = read_f(&line[0], fd, &stock, str)) == -1)
        return (-1);
    free(str);
    if (ret == 0 && ft_strlen(line[0]) == 0)
        return (0);
    return (1);
}

int        main(int argc, char **argv)
{
    int        fd;
    char    *line;
    int        i;
    int        ret;

    i = 0;
    (void)argc;
    fd = open("prueba.txt", O_RDONLY);
    while (i < 5)
    {
        line = (char *)malloc(sizeof(*line) * 1);
        ret = get_next_line(fd, &line);
        printf("|%s|\n", line);
        i++;
    }
}