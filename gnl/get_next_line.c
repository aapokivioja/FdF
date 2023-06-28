/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 19:54:44 by akivioja      #+#    #+#                 */
/*   Updated: 2023/03/01 16:55:56 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
- combines res and buffer from the function "read_file" using strjoin
- frees buffer
- returns the joined strings
*/
char	*free_func(char *buffer, char *buf)
{
	char	*join;

	join = ft_strjoin(buffer, buf);
	if (join == NULL)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	free(buffer);
	return (join);
}

/*
- Takes buffer as input and returns the next line as a string
- used to set the new value to buffer variable in gnl
- Allocates memory for the new line with malloc
- Iterates through buffer until end of file or new line
- Frees buffer as its no longer needed
*/

char	*next_line(char *buffer)
{
	size_t	count;
	size_t	index;
	char	*line;

	count = 0;
	index = 0;
	while (buffer[count] && buffer[count] != '\n')
		count++;
	if (!buffer[count])
		return (free(buffer), NULL);
	if (buffer[count] == '\n')
		count++;
	line = malloc((ft_strlen(buffer) - count + 1) * sizeof(char));
	if (!line)
		return (free(buffer), NULL);
	while (buffer[count])
		line[index++] = buffer[count++];
	line[index] = '\0';
	free(buffer);
	return (line);
}

/*
- Takes buffer and returns string containing the current line
- Allocates memory with calloc
- Iterates through buffer until end of file or new line
- returns **current** line to gnl
*/

char	*get_linex(char *buffer)
{
	char	*line;
	size_t	count;

	count = 0;
	if (!buffer[count])
		return (NULL);
	while (buffer[count] && buffer[count] != '\n')
		count++;
	if (buffer[count] == '\n')
		count++;
	line = ft_calloc(count + 1, sizeof(char));
	if (!line)
		return (NULL);
	count = 0;
	while (buffer[count] && buffer[count] != '\n')
	{
		line[count] = buffer[count];
		count++;
	}
	if (buffer[count] && buffer[count] == '\n')
		line[count++] = '\n';
	return (line);
}

/*
- Takes fd to use it for read
- Takes res which and appends data from read to be returned
- Reads until reaches end of the file or error occurs
- free_func appends the data to res
*/

char	*read_file(int fd, char *res)
{
	char	*buffer;
	ssize_t	byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (free(res), NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(res), free(buffer), NULL);
		buffer[byte_read] = '\0';
		res = free_func(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_linex(buffer);
	buffer = next_line(buffer);
	return (line);
}
