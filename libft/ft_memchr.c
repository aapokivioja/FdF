/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:12:36 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/23 13:08:26 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_str;
	unsigned char	c_char;

	s_str = (unsigned char *)s;
	c_char = (unsigned char)c;
	while (n)
	{
		if (*s_str == c_char)
			return (s_str);
		n--;
		s_str++;
	}
	return (NULL);
}
