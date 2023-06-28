/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 16:44:56 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/21 16:53:45 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_str;
	unsigned char	*src_str;
	int				count;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_str = (unsigned char *)dst;
	src_str = (unsigned char *)src;
	count = 0;
	while (n > 0)
	{
		dst_str[count] = src_str[count];
		count++;
		n--;
	}
	return (dst);
}
