/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 16:10:53 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/23 21:58:37 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	int		needle_count;
	size_t	tmp;
	int		needle_len;

	count = 0;
	needle_count = 0;
	needle_len = 0;
	while (needle[needle_len] != '\0')
		needle_len++;
	if (needle_len == 0)
		return ((char *)haystack);
	while (haystack[count] != '\0' && count < len)
	{
		tmp = count;
		needle_count = 0;
		while (haystack[tmp++] == needle[needle_count] && tmp <= len)
		{
			if (needle_count == needle_len - 1)
				return ((char *)&haystack[count]);
			needle_count++;
		}
		count++;
	}
	return (NULL);
}
