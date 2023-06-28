/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 12:05:05 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/26 12:25:07 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*j_str;
	int		j_str_c;

	s1_len = 0;
	s2_len = 0;
	j_str_c = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	j_str = malloc((s1_len + s2_len) + sizeof(char) + 1);
	if (j_str == NULL)
		return (NULL);
	while (*s1)
		j_str[j_str_c++] = *s1++;
	while (*s2)
		j_str[j_str_c++] = *s2++;
	j_str[j_str_c] = '\0';
	return (j_str);
}
