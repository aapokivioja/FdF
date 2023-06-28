/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/29 15:51:35 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/29 15:51:38 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	count;

	count = 0;
	str = ft_strdup(s);
	if (!(str))
		return (NULL);
	while (s[count])
	{
		str[count] = (*f)(count, str[count]);
		count++;
	}
	return (str);
}
