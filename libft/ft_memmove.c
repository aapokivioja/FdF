/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 17:15:52 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/12 16:36:48 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_str;
	const char	*src_str;
	const char	*last_src;
	char		*last_dst;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_str = (char *)dst;
	src_str = (char *)src;
	if (dst_str < src_str)
		while (len--)
			*dst_str++ = *src_str++;
	else
	{
		last_src = src_str + (len - 1);
		last_dst = dst_str + (len - 1);
		while (len--)
			*last_dst-- = *last_src--;
	}
	return (dst);
}
