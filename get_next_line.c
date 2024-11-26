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

size_t	get_line_len(char *full_line)
{
	size_t	i;

	i = 0;
	while (full_line)
	{
		if (full_line[i] == '\n' || full_line[i] == '\0')
			return (i);
		else
			i++;
	}
	printf("len = %i", i);
	return (i);
}

char	*get_line(char *full_line)
{
	char	*line;
	size_t	i;
		
	i = 0;
	line = malloc(sizeof(char) * (get_line_len(full_line) + 1));
	if (!line)
		return (NULL);
	while (full_line[i] != '\n' || full_line[i] == '\0')
	{
		line[i] = full_line[i]; 
		i++;
	}
	line[i] = full_line[i];
	line[++i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*full_line;
	size_t		rbytes;
	size_t		i;

	rbytes = 42;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (rbytes > 0 || full_line)
	{	
		rbytes = read(fd, buffer, BUFFER_SIZE);
		buffer[rbytes] = '\0';
		if (rbytes <= 0)
			break ;
		if (full_line == NULL)
			full_line = ft_strdup(buffer);
		else
			full_line = ft_strjoin(full_line, buffer);
	}
	line = get_line(full_line);
	i = 0;
	full_line = ft_substr(full_line, ft_strlen(line), ft_strlen(full_line) - ft_strlen(line) + 1);
	printf("full_line: %s", full_line);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Resultado 1: %s", line);
	line = get_next_line(fd);
	printf("Resultado 2: %s", line);
	return (0);
}