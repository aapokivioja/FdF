/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 19:54:54 by akivioja      #+#    #+#                 */
/*   Updated: 2023/03/01 16:40:37 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j_str;
	int		count;

	if (!s1 || !s2)
		return (NULL);
	j_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!j_str)
		return (NULL);
	count = 0;
	while (*s1)
		j_str[count++] = *s1++;
	while (*s2)
		j_str[count++] = *s2++;
	j_str[count] = '\0';
	return (j_str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
//copied

void	ft_bzero(void *str, size_t n)
{
	char	*str_b;
	size_t	index;

	str_b = (char *)str;
	index = 0;
	while (index < n)
	{
		str_b[index] = '\0';
		index++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	str = malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}
