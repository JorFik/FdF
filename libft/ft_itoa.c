/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:54:13 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/16 21:26:36 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_a_init(long n)
{
	char	*a;
	double	w_i;
	int		count;

	count = 0;
	w_i = (double) n;
	if (n < 0)
		count ++;
	if (n < 0)
		w_i *= -1.0;
	while ((w_i / 10.0) >= (1.0 / 10.0))
	{
		w_i /= 10.0;
		count++;
	}
	if (!n)
		count = 1;
	a = ft_calloc(count + 1, sizeof(char));
	if (!a)
		return (0);
	if (n < 0)
		a[0] = '-';
	return (a);
}

static long	ft_i_init(long n)
{
	double	w_i;
	int		count;

	count = 0;
	w_i = (double) n;
	if (n < 0)
		count ++;
	if (n < 0)
		w_i *= -1.0;
	while ((w_i / 10.0) >= (1.0 / 10.0))
	{
		w_i /= 10.0;
		count++;
	}
	if (!n)
		count = 1;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*a;
	double	w_i;
	long	i;

	w_i = (double) n;
	a = ft_a_init(n);
	if (!a)
		return (0);
	i = ft_i_init(n) - 1;
	if (w_i < 0.0)
		w_i = -w_i;
	while ((w_i / 10.0) >= (1.0 / 10.0) && i + 1 && a[i] != '-')
	{
		a[i] = ((long)w_i % 10) + '0';
		w_i /= 10.0;
		i --;
	}
	if (!n)
		a[0] = '0';
	return (a);
}

		// printf("i = %li\n", i);
// printf("entre\nguardare en a[%li]: %c\n", i, (char)(((long)w_i % 10) + '0'));
// int	main(void)
// {
// 	char	*a;

// 	printf("your new a: %s", a = ft_itoa(-123));
// 	free(a);
// 	return (0);
// }
