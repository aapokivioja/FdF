/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 10:44:36 by akivioja      #+#    #+#                 */
/*   Updated: 2022/10/23 13:18:15 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	count;
	int	neg;
	int	answer;

	count = 0;
	neg = 1;
	answer = 0;
	while (str[count] == 32 || (str[count] > 8 && str[count] < 14))
		count++;
	if (str[count] == 45)
	{
		neg *= -1;
		count++;
	}
	else if (str[count] == 43)
		count++;
	while (str[count] >= 48 && str[count] <= 57)
	{
		answer = answer * 10 + (str[count] - 48);
		count++;
	}
	return (answer * neg);
}
