/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:05:50 by labia-fe          #+#    #+#             */
/*   Updated: 2024/11/27 17:32:18 by labia-fe         ###   ########.fr       */
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

size_t	get_line_len(char *temp)
{
	size_t	i;

	i = 0;
	while (temp)
	{
		if (temp[i] == '\n')
			return (i + 1);
		else if (temp[i] == '\0')
			return (i);
		else
			i++;
	}
	printf("len = %zu", i);
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
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*buffer;
	char		*line;
	size_t		rbytes;
	
	rbytes = 1;	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!buffer)
		return (NULL);
	buffer[0] = '\0';
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
	free(buffer);
	line = get_line(temp);
	temp = ft_substr(temp, ft_strlen(line), ft_strlen(temp) - ft_strlen(line) + 1);
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("linea %d: %s", i, line);
		free(line);
		i++;
	}
	return (0);
}