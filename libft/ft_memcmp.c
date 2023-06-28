/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 14:38:28 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/23 13:08:53 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				count;
	unsigned char		*s1_str;
	unsigned char		*s2_str;

	count = 0;
	s1_str = (unsigned char *)s1;
	s2_str = (unsigned char *)s2;
	while (count < n)
	{
		if (s1_str[count] != s2_str[count])
			return (s1_str[count] - s2_str[count]);
		count++;
	}
	return (0);
}
