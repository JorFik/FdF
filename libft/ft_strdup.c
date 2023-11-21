/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:06:32 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/16 22:18:32 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*new_p;
	int		size_s1;

	size_s1 = ft_strlen(s1);
	new_p = (char *) malloc((size_s1 + 1) * sizeof(char));
	if (new_p == (void *)0)
		return ((void *)0);
	ft_memcpy(new_p, s1, size_s1 + 1);
	return (new_p);
}
