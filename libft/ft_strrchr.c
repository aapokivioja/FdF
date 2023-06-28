/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 17:12:59 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/23 19:47:54 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;

	count = 0;
	while (*s)
	{
		s++;
		count++;
	}
	if (c == '\0')
		return ((char *)s);
	while (*s != (char)c)
	{
		if (count == 0)
			return (NULL);
		s--;
		count--;
	}
	return ((char *)s);
}
