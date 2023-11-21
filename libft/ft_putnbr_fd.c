/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:23:56 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/26 17:09:10 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = (long) n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n < 0)
		nbr = -nbr;
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	if (nbr > 9)
		ft_putnbr_fd(nbr % 10, fd);
	else
		ft_putchar_fd(nbr + '0', fd);
	return ;
}

// int	main(void)
// {
// 	ft_putnbr_fd(-2147483647 -1, 1);
// 	return (0);
// }
