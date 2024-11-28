/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:32:30 by labia-fe          #+#    #+#             */
/*   Updated: 2024/11/27 15:11:34 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlen(char *s);

char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*get_line(char *temp);
char	*ft_strdup(char *s);

#endif