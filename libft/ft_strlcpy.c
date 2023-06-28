/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 17:28:12 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/23 14:44:51 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	src_len;

	count = 1;
	src_len = 0;
	while (src[src_len] != '\0')
	{
		if (dstsize > count)
		{
			dst[src_len] = src[src_len];
			count++;
		}
		src_len++;
	}
	if (dstsize >= count)
		dst[count - 1] = '\0';
	return (src_len);
}
