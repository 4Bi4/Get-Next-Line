/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:10:38 by labia-fe          #+#    #+#             */
/*   Updated: 2024/12/01 04:14:46 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*get_line(char	*str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!line)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		line[i] = str[i];
		i++;
	}
	line[i] = str[i];
	line[i + 1] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*line;
	char		*temp;
	int			rbytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rbytes = 42;
	while (rbytes > 0 && !ft_strchr(str, '\n'))
	{
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes < 0)
		{
			free (buffer);
			return (NULL);
		}
		buffer[rbytes] = '\0';
		if (!str)
			str = ft_strdup(buffer);
		else
			str = ft_strjoin(str, buffer);
	}
	free(buffer);
    if (rbytes == 0 && (!str || !*str))
    {
        free(str);
        str = NULL;
        return (NULL);
    }
	line = get_line(str);
	temp = str;
	str = ft_substr(temp, ft_strlen(line), ft_strlen(temp) - ft_strlen(line));
	free (temp);
	return (line);
}


int	main(void)
{
	char	*line;
	int		fd;
	size_t	i;
	
	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("line %zu: %s", i++, line);
		free(line);
	}
	return (0);
}
