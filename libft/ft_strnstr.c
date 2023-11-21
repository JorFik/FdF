/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:45:18 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/16 22:34:16 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, unsigned long len)
{
	unsigned long	match;
	unsigned long	i;
	unsigned long	size_needle;

	size_needle = ft_strlen(needle);
	i = 0;
	if (ft_strlen(needle) == 0 || haystack == needle)
		return ((char *) haystack);
	while (i < len && len > 0 && *haystack != '\0'
		&& !(size_needle > ft_strlen(haystack)))
	{
		match = 0;
		while (haystack[i] == needle[match]
			&& i < len && (haystack[i] || needle[match]))
		{
			match ++;
			i ++;
		}
		if (match == size_needle)
			return (&((char *)haystack)[i - size_needle]);
		i -= match;
		i ++;
	}
	return (0);
}
