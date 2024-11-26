/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:31:40 by labia-fe          #+#    #+#             */
/*   Updated: 2024/11/26 11:32:54 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;
	size_t	i;


	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	ptr = malloc(len1 + len2 + 1);
	if (!ptr)
		return (NULL);
	while (i < len1)
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		ptr[len1 + i] = s2[i];
		i++;
	}
	ptr[len1 + i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
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

char	*ft_strdup(char *s)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	ptr = malloc(len + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*ptr;
// 	size_t	srclen;

// 	srclen = ft_strlen(s);
// 	if (!s)
// 		return (NULL);
// 	if (srclen < start)
// 		return (ft_strdup(""));
// 	if (start + len > srclen)
// 		len = srclen - start;
// 	ptr = malloc(sizeof(char) * (len + 1));
// 	if (!ptr)
// 		return (NULL);
// 	ft_strlcpy(ptr, s + start, len + 1);
// 	return (ptr);
// }
