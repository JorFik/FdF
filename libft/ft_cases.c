/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:35:54 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/07 17:04:57 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (s)
	{
		while (s[i])
		{
			tmp = ft_putchar(s[i]);
			if (tmp == -1)
				return (-1);
			i ++;
		}
	}
	if (!s)
		return (ft_putstr("(null)"));
	return (i);
}

static int	ft_putnbr(long n, int flag)
{
	static int	fd;
	int			tmp;

	if (flag == 0)
		fd = 0;
	if (n < 0)
	{
		tmp = ft_putchar('-');
		if (tmp == -1)
			return (tmp);
		fd += tmp;
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10, 1);
	if (n > 9)
		ft_putnbr(n % 10, 1);
	else
	{
		tmp = ft_putchar(n + '0');
		fd += tmp;
		if (tmp == -1)
			return (-1);
	}
	return (fd);
}

int	ft_cases(const char *formato, va_list input)
{
	int	flag_prints;
	int	i;

	i = 1;
	flag_prints = 0;
	while (ft_is_bonus_flag(&formato[i]))
	{
		flag_prints = ft_bonus_flags(&formato[i], input);
		if (!flag_prints)
			return (-1);
		i ++;
	}
	if (formato[i] == 'c')
		return (ft_putchar(va_arg(input, int)) + flag_prints);
	if (formato[i] == 's')
		return (ft_putstr(va_arg(input, char *)) + flag_prints);
	if ((formato[i] == 'd' || formato[i] == 'i'))
		return (ft_putnbr(va_arg(input, int), 0) + flag_prints);
	if (formato[i] == 'u')
		return (ft_putnbr(va_arg(input, unsigned int), 0) + flag_prints);
	if (formato[i] == '%')
		return (ft_putchar ('%'));
	return (ft_hex_cases(formato, input) + flag_prints);
}

// ~ %c char
// ~ %s str
// ~ %i int base 10
// ~ %d decimal base 10 number same shit as %i
// ~ %u unsigned int base 10