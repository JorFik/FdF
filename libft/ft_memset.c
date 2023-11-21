/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:36:20 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/11 14:45:39 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *address, int c, unsigned long size)
{
	unsigned long	i;
	unsigned char	filler;

	i = 0;
	filler = (unsigned char) c;
	while (size > i)
	{
		((unsigned char *) address)[i] = filler;
		i ++;
	}
	return (address);
}

// int	main(void)
// {
// 	char str[50] = "GeeksForGeeks is for programming geeks.";

// 	printf("Before memset(): %s\n", str);
// 	ft_memset(str + 13, '.', 8 * sizeof(unsigned char));
// 	printf("After memset():  %s", str);
// 	return (0);
// }
