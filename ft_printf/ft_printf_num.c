/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_num.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 14:50:07 by akivioja      #+#    #+#                 */
/*   Updated: 2023/03/21 16:41:27 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	print_ptr(uintptr_t ptr)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (len == -1)
		return (-1);
	len += rec_hex(ptr, 'p', 0);
	return (len);
}

int	int_len(int nbr)
{
	int	len;

	len = 0;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	else if (nbr == 0)
		return (1);
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	len++;
	return (len);
}

int	unsigned_len(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	len++;
	return (len);
}

int	print_nbr(int nbr)
{
	int	len;
	int	min;

	min = ft_putnbr_fd(nbr, 1);
	len = int_len(nbr);
	if (min == -1)
		return (-1);
	return (len);
}

int	put_unsignednum(unsigned int nbr)
{
	unsigned int	nro;
	int				min;

	nro = (unsigned int)nbr;
	min = 0;
	if (nro >= 10)
		min = ft_putnbr_fd(nro / 10, 1);
	if (min == -1)
		return (-1);
	min = ft_putchar_fd((char)(nro % 10 + 48), 1);
	return (min);
}
