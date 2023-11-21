/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:13:58 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/12 12:50:31 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, unsigned long len)
{
	char	*new_s;

	if (ft_strlen(s) <= start)
		return (ft_calloc(1, 1));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	if (len < ft_strlen(&s[start]))
	{
		new_s = (char *) malloc((len + 1) * sizeof(char));
		if (new_s == (void *)0)
			return ((void *)0);
		ft_memcpy(new_s, &s[start], len + 1);
		new_s[len] = '\0';
	}
	else
	{
		new_s = (char *) malloc((ft_strlen(&s[start]) + 1) * sizeof(char));
		if (new_s == (void *)0)
			return ((void *)0);
		ft_memcpy(new_s, &s[start], len + 1);
		new_s[len] = '\0';
	}
	return (new_s);
}
