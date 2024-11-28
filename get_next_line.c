/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:05:50 by labia-fe          #+#    #+#             */
/*   Updated: 2024/11/28 20:12:43 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*get_line(char *temp)
{
	char	*line;
	size_t	i;

	if (temp == NULL)
		return (NULL);
	i = 0;
	while (temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	line = ft_substr(temp, 0, i);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*temp2;
	char		*buffer;
	char		*line;
	size_t		rbytes;
	
	rbytes = 1;	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return (NULL);
	while (rbytes > 0 && !(ft_strchr(buffer, '\n')))
		{
			rbytes = read(fd, buffer, BUFFER_SIZE);
			buffer[rbytes] = '\0';
			if (rbytes <= 0)
				return (NULL);
			if (temp == NULL)
				temp = ft_strdup(buffer);
			else
				temp = ft_strjoin(temp, buffer);		
		}
	line = get_line(temp);
	temp2 = temp;
	temp = ft_substr(temp, ft_strlen(line), ft_strlen(temp) - ft_strlen(line) + 1);
	free (temp2);
	return (line);
}

int	main(void)
{
	size_t		fd;
	size_t		i;
	char		*line;

	i = 1;
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		printf("linea %zu: %s", i, line);
		free(line);
		i++;
	}
	return (0);
}