/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:21:06 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/28 23:45:59 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_putnbr_hex(unsigned long long n, int flag)
{
	static int	fd;
	int			tmp;

	tmp = 0;
	if (flag == 0)
		fd = 0;
	if (n > 15)
		tmp = ft_putnbr_hex(n / 16, 1);
	if (n > 15)
		tmp = ft_putnbr_hex(n % 16, 1);
	else
	{
		if (n < 10)
			tmp = ft_putchar(n + '0');
		else
			tmp = ft_putchar(n + 'a' - 10);
		if (tmp == -1)
			return (tmp);
		fd += tmp;
	}
	if (tmp == -1)
		return (tmp);
	return (fd);
}

static int	ft_putnbr_hex_up(unsigned long long n, int flag)
{
	static int	fd;
	int			tmp;

	tmp = 0;
	if (flag == 0)
		fd = 0;
	if (n > 15)
		tmp = ft_putnbr_hex_up(n / 16, 1);
	if (n > 15)
		tmp = ft_putnbr_hex_up(n % 16, 1);
	else
	{
		if (n < 10)
			tmp = ft_putchar(n + '0');
		else
			tmp = ft_putchar(n + 'A' - 10);
		if (tmp == -1)
			return (tmp);
		fd += tmp;
	}
	if (tmp == -1)
		return (tmp);
	return (fd);
}

static int	ft_putnbr_uhex(unsigned long long n, int flag)
{
	static int			fd;
	int					tmp;

	tmp = 0;
	if (flag == 0)
		fd = 0;
	if (n > 15)
		tmp = ft_putnbr_uhex(n / 16, 1);
	if (n > 15)
		tmp = ft_putnbr_uhex(n % 16, 1);
	else
	{
		if (n < 10)
			tmp = ft_putchar(n + '0');
		else
			tmp = ft_putchar(n + 'a' - 10);
		if (tmp == -1)
			return (tmp);
		fd += tmp;
	}
	if (tmp == -1)
		return (tmp);
	return (fd);
}

int	ft_hex_cases(const char *formato, va_list input)
{
	if (formato[1] == 'p')
	{
		if (ft_putchar('0') == -1)
			return (-1);
		if (ft_putchar('x') == -1)
			return (-1);
		return (ft_putnbr_uhex(va_arg(input, unsigned long long), 0) + 2);
	}
	if (formato[1] == 'X')
		return (ft_putnbr_hex_up(va_arg(input, unsigned int), 0));
	if (formato[1] == 'x')
		return (ft_putnbr_hex(va_arg(input, unsigned int), 0));
	return (0);
}
	// ft_putstr("Invalid format\nValid formats: c, s, p, d, i, u, x, X, %\n");
// ! Returns should be bytes printed + 1

// ~ %p (void *) in hexadecimal format
// ~ %x %X hexadecimal uppercase or lowercase
// ~ %% prints '%'