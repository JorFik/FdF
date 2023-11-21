/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:45:59 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/16 22:15:51 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, unsigned long len)
{
	int	i;

	i = 0;
	if (src > dst)
	{
		while (len --)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i ++;
		}
	}
	else if (src < dst)
	{
		while (len --)
			*(char *)(dst + len) = *(char *)(src + len);
	}
	return (dst);
}

// int	main(void)
// {
// 	char	str[100] = "Learningisfun";
// 	char	*first, *second;

// 	first = str;
// 	second = str;
// 	printf("Original string :%s\n ", str);
// 	ft_memcpy(first + 8, first, 10);
// 	printf("memcpy overlap : %s\n ", str);
// 	ft_memmove(second + 8, first, 10);
// 	printf("memmove overlap : %s\n ", str);
// 	return (0);
// }

// int	main(void)
// {
// 	char str1[17] = "abcdef";
// 	char str2[17] = "abcdef";

// 	printf("The string: %s\n", str1);
// 	memcpy((str1 + 6), str1, 10);
// 	printf("New string: %s\n", str1);

// 	printf("The string: %s\n", str2);
// 	memmove((str1 + 6), str2, 10);
// 	printf("New string: %s\n", str2);
// }
