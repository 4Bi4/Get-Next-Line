/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:29:26 by labia-fe          #+#    #+#             */
/*   Updated: 2024/11/26 11:31:19 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *full_line)
{
	char	*line;
	size_t	i;

	i = 0;
	while (full_line[i] != '\n')
	{
		line [i] = full_line [i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*full_line = NULL;
	size_t		rbytes;
	size_t		linelen;
	size_t		i;

	rbytes = 42;
	linelen = 0;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (rbytes > 0)
	{
		rbytes = read(fd, buffer, BUFFER_SIZE);
		if (rbytes <= 0)
			return (NULL);
		if (full_line = NULL)
		{
			full_line = ft_strdup(buffer);
			printf("funciona?? = %s", full_line);
		}
		else
		{
			printf("SE METE A ELSE\n");
			printf("buffer = %s\n", buffer);
			printf("s1 = %s\n", full_line);
			full_line = ft_strjoin(full_line, buffer);
		}
	}
	line = get_line(full_line);
	linelen = ft_strlen(line);
	i = 0;
	while (i <= linelen)
	{
		full_line[i] = '\0';
		i++;
	}
	return (line);
}

#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	printf("fd: %d\n", fd);
	line = get_next_line(fd);
	printf("Resultado: %s\n", line);
	return (0);
}