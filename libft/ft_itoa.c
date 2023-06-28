/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 17:29:34 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/27 17:29:38 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_len(long num, int str_s)
{
	long	num_l;

	num_l = num;
	while (num_l > 0)
	{
		num_l /= 10;
		str_s++;
	}
	return (str_s);
}

void	is_neg(long neg, char *str_n)
{
	if (neg < 0)
		str_n[0] = '-';
}

char	*is_zero(char *str_n)
{
	str_n[0] = '0';
	str_n[1] = '\0';
	return (str_n);
}

void	logic(long num, char *str_n, int str_s)
{
	str_n[str_s--] = '\0';
	while (num > 0)
	{
		str_n[str_s--] = num % 10 + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	long	num;
	int		str_s;
	long	neg;
	char	*str_n;

	str_s = 0;
	neg = 1;
	num = n;
	if (n < 0)
	{
		str_s++;
		neg *= -1;
		num = n * neg;
	}
	str_s = int_len(num, str_s);
	if (n == 0)
		str_s = 1;
	str_n = (char *)malloc((str_s + 1) * sizeof(char));
	if (!str_n)
		return (NULL);
	if (n == 0)
		return (is_zero(str_n));
	is_neg(neg, str_n);
	logic(num, str_n, str_s);
	return (str_n);
}
