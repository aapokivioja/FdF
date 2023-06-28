/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:07:34 by akivioja      #+#    #+#                 */
/*   Updated: 2023/02/15 14:50:42 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		print_unsigned(unsigned int nbr);
int		print_percent(void);
int		format(va_list args, const char format);

int		print_char(int c);
int		print_str(char *s);
void	ptr_prefix(void);
int		rec_hex_helper(uintptr_t ptr, char format);
int		rec_hex(uintptr_t ptr, char format, int check);

int		print_ptr(uintptr_t ptr);
int		int_len(int nbr);
int		unsigned_len(unsigned int nbr);
int		print_nbr(int nbr);
int		put_unsignednum(unsigned int nbr);

#endif