/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 11:05:49 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/26 12:19:23 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			str_l;
	size_t			sub_count;
	char			*sub_str;

	sub_count = 0;
	str_l = ft_strlen(s);
	if (str_l - start < len)
		len = str_l - start;
	if (start >= str_l)
	{
		sub_str = (char *)malloc(1);
		if (!sub_str)
			return (NULL);
		sub_str[0] = '\0';
		return (sub_str);
	}
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
