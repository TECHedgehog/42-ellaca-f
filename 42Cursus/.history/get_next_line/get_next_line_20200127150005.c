/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:04:14 by ellaca-f          #+#    #+#             */
/*   Updated: 2020/01/27 15:00:05 by ellaca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	size_t			i;

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

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (&str[i]);
		i++;
	}
	if (s[i] == c)
		return (&str[i]);
	return (0);
}

int		recycle_bin(char **leftover, char **line)
{
	int			len;

	if (ft_strchr(*leftover, '\n') != NULL)
	{
		len = ft_strchr(*leftover, '\n') - *leftover;
		line[0] = ft_substr(*leftover, 0, len);
		*leftover = ft_strchr(*leftover, '\n') + 1;
		return (1);
	}
	line[0] = ft_strdup(*leftover);
	*leftover = NULL;
	return (0);
}

int		reader(char **line, int fd, char **leftover, char *str)
{
	char		*temp;
	int			len;
	int			bites_read;

	while ((bites_read = read(fd, str, BUFFER_SIZE)))
	{
		if (bites_read == -1)
			return (bites_read);
		str[bites_read] = '\0';
		temp = ft_strdup(line[0]);
		free(line[0]);
		line[0] = ft_strjoin(temp, str);
		free(temp);
		if (ft_strchr(line[0], '\n'))
		{
			len = ft_strchr(line[0], '\n') - line[0];
			*leftover = ft_strdup(ft_strchr(line[0], '\n') + 1);
			temp = strdup(line[0]);
			free(line[0]);
			line[0] = ft_substr(temp, 0, len);
			free(temp);
			break ;
		}
	}
	return (bites_read);
}

int		get_next_line(int fd, char **line)
{
	int			bites_read;
	char		*str;
	static char	*leftover;
	
	if (line == NULL || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	line[0] = ft_strnew(BUFFER_SIZE);
	if (leftover != NULL)
		if (recycle_bin(&leftover, &line[0]))
			return (1);
	if ((bites_read = reader(&line[0], fd, &leftover, str)) == -1)
		return (-1);
	free(str);
	if (bites_read == 0 && ft_strlen(line[0]) == 0)
		return (0);
	return (1);
}
