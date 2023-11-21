/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:29:51 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/07 17:03:33 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_printf_formato(const char *formato)
{
	int	i;

	i = 0;
	while (formato[i] && formato[i] != '%')
	{
		if (ft_putchar(formato[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_is_bonus_flag(const char *formato)
{
	if (*formato == '#' || *formato == ' ' || *formato == '+'
		|| ft_isdigit(*formato) || *formato == '.' || *formato == '-')
		return (1);
	return (0);
}

static int	ft_jump_specifiers(const char *formato)
{
	int	i;

	i = 0;
	while (ft_is_bonus_flag(&formato[i]))
		i++;
	if (formato[i] == 'c' || formato[i] == 's' || formato[i] == 'd'
		|| formato[i] == 'i' || formato[i] == 'u' || formato[i] == '%'
		|| formato[i] == 'p' || formato[i] == 'X' || formato[i] == 'x')
		i ++;
	else
		return (2);
	return (i + 1);
}

int	ft_printf(const char *formato, ...)
{
	int				bytes_printed;
	int				tmp;
	int				i;
	va_list			input;

	va_start(input, formato);
	bytes_printed = 0;
	i = 0;
	while (formato[i])
	{
		if (formato[i] != '%')
			tmp = ft_printf_formato(&formato[i]);
		if (formato[i] != '%')
			i += tmp;
		else if (formato[i] == '%')
		{
			tmp = ft_cases(&formato[i], input);
			i += ft_jump_specifiers(&formato[i] + 1);
		}
		bytes_printed += tmp;
		if (tmp == -1)
			return (-1);
	}
	va_end(input);
	return (bytes_printed);
}

// int	main(void)
// {
// 	int	a;
// 	int	c;

// 	a = ft_printf ("ft_printf = %d %i %u", -120932, -120932, -120932);
// 	ft_printf("\n");
// 	c = printf ("   printf = %d %i %u", '0', '0', '1');
// 	printf ("\nft_printf = %d\n   printf = %d\n     Diff = %d\n", a, c, a - c);
// 	return (0);
// }
