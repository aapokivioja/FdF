/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 17:50:54 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/23 22:49:02 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				count;
	unsigned char	*addy;

	addy = (unsigned char *)b;
	count = 0;
	while (len > 0)
	{
		addy[count] = (unsigned char) c;
		count++;
		len--;
	}
	return (b);
}
