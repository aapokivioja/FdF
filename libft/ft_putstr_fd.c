/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:24:34 by akivioja      #+#    #+#                 */
/*   Updated: 2023/02/15 14:55:43 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;
	int	min;

	count = 0;
	while (*s)
	{
		min = write (fd, s++, 1);
		if (min == -1)
			return (-1);
		count++;
	}
	return (count);
}
