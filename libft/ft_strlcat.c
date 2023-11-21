/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:46:00 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/16 22:21:14 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long dst_size)
{
	unsigned long	src_size;
	unsigned long	counter;

	counter = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dst_size < counter)
		return (src_size + dst_size);
	ft_strlcpy(&dst[counter], src, dst_size - counter);
	return (counter + src_size);
}

// int    main(void)
//  {
//      char    str[25] = "conseipsum dolor sit a";
//      char    str1[25] = "conseipsum dolor sit a";
//      char    first[25] = "aaaaaaaaaaaaaaaaaaaaaaaa";
//      char    second[25] = "";

//      printf("Original string :%s\n ", str);
//     // strlcpy(first, str, 1);
//      printf("memcpy overlap : %s\n ", str);
//      ft_strlcpy(second, str1, 0);
//      printf("memmove overlap : %s\n ", second);
//      return (0);
//  }