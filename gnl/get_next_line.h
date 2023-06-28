/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/16 19:55:56 by akivioja      #+#    #+#                 */
/*   Updated: 2023/02/28 19:07:08 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* header file */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);

char	*ft_line_helper(char	*buffer);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif