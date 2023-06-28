/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 15:32:20 by akivioja      #+#    #+#                 */
/*   Updated: 2023/02/15 14:52:45 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nro;
	int				min;

	min = 0;
	if (n < 0)
	{
		min = ft_putchar_fd('-', fd);
		nro = (unsigned int)(n * -1);
	}
	else
		nro = (unsigned int)n;
	if (min == -1)
		return (-1);
	if (nro >= 10)
		min = ft_putnbr_fd(nro / 10, fd);
	if (min == -1)
		return (-1);
	min = ft_putchar_fd((char)(nro % 10 + 48), fd);
	if (min == -1)
		return (-1);
	return (0);
}
