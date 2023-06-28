/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 17:25:16 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/23 19:21:31 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dst_cpy;
	const char	*s_cpy;
	size_t		buff;
	size_t		dst_len;

	dst_cpy = dst;
	s_cpy = src;
	buff = dstsize;
	while (buff-- != 0 && *dst_cpy != '\0')
		dst_cpy++;
	dst_len = dst_cpy - dst;
	buff = dstsize - dst_len;
	if (buff == 0)
		return (dst_len + ft_strlen(s_cpy));
	while (*s_cpy != '\0')
	{
		if (buff != 1)
		{
			*dst_cpy++ = *s_cpy;
			buff--;
		}
		s_cpy++;
	}
	*dst_cpy = '\0';
	return (dst_len + (s_cpy - src));
}
