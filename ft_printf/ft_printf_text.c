/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_text.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 14:50:18 by akivioja      #+#    #+#                 */
/*   Updated: 2023/03/21 16:41:31 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *s)
{
	int	len;
	int	min;

	len = 0;
	if (s == NULL)
	{
		return (ft_putstr_fd("(null)", 1));
	}
	while (*s)
	{
		min = write (1, s++, 1);
		if (min == -1)
			return (-1);
		len++;
	}
	return (len);
}

void	ptr_prefix(void)
{
	write (1, "0x", 2);
}

int	rec_hex_helper(uintptr_t ptr, char format)
{
	uintptr_t	tmp;
	char		digit;

	tmp = ptr % 16;
	if (tmp < 10)
		digit = tmp + 48;
	else
	{
		if (format == 'x' || format == 'p')
			digit = tmp - 10 + 'a';
		else if (format == 'X')
			digit = tmp - 10 + 'A';
		else
			return (-1);
	}
	return (write(1, &digit, 1));
}

int	rec_hex(uintptr_t ptr, char format, int check)
{
	int	len;
	int	res;

	len = 0;
	if (ptr == 0 && check == 0)
		return (write(1, "0", 1));
	if (ptr != 0)
	{
		res = rec_hex(ptr / 16, format, 1);
		if (res == -1)
			return (-1);
		len += res;
		res = rec_hex_helper(ptr, format);
		if (res == -1)
			return (-1);
		len += res;
	}
	return (len);
}
