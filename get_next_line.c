/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:10:38 by labia-fe          #+#    #+#             */
/*   Updated: 2024/12/02 13:46:56 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*buffer_manager(int fd, char *str, char *buffer)
{
	char	*temp;
	int		rbytes;

	rbytes = 1;
	while (rbytes > 0 && !ft_strchr(str, '\n'))
	{
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rbytes] = '\0';
		temp = str;
		if (!str)
			str = ft_strdup(buffer);
		else
			str = ft_strjoin(str, buffer);
		free(temp);
	}
	free(buffer);
	return (str);
}

static char	*process_line(char **str)
{
	char	*line;
	char	*temp;

	if (!str || !*str || !**str)
		return (NULL);
	line = get_line(*str);
	temp = *str;
	*str = ft_substr(temp, ft_strlen(line), ft_strlen(temp) - ft_strlen(line));
	free(temp);
	if (!*str || !**str)
	{
		free(*str);
		*str = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	str = buffer_manager(fd, str, buffer);
	if (!str)
	{
		free(str);
		str = NULL;
	}
	line = process_line(&str);
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
	printf("\n");
	close (fd);
	return (0);
}
