/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 15:19:43 by akivioja      #+#    #+#                 */
/*   Updated: 2023/03/21 16:43:47 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	print_unsigned(unsigned int nbr)
{
	int	len;
	int	min;

	min = put_unsignednum(nbr);
	len = unsigned_len(nbr);
	if (min == -1)
		return (-1);
	return (len);
}

int	print_percent(void)
{
	return (write (1, "%", 1));
}

int	format(va_list args, const char format)
{
	int	pr_len;

	pr_len = 0;
	if (format == 'c')
		pr_len += print_char(va_arg(args, int));
	else if (format == 's')
		pr_len += print_str(va_arg(args, char *));
	else if (format == 'p')
		pr_len += print_ptr(va_arg(args, uintptr_t));
	else if (format == 'd' || format == 'i')
		pr_len += print_nbr(va_arg(args, int));
	else if (format == 'u')
		pr_len += print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		pr_len += rec_hex(va_arg(args, unsigned int), format, 0);
	else if (format == '%')
		pr_len += print_percent();
	return (pr_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		prlen;
	int		count;

	prlen = 0;
	count = 0;
	va_start(args, str);
	while (str[count])
	{
		if (str[count] == '%')
		{
			prlen += format(args, str[++count]);
		}
		else
		{
			prlen += print_char(str[count]);
		}
		if (prlen < 0)
			return (-1);
		if (str[count] != '\0')
			count++;
	}
	va_end(args);
	return (prlen);
}
