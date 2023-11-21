/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:53:12 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/16 22:20:33 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	int		size_s1;
	int		size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen (s2);
	new_s = ft_calloc(size_s1 + size_s2 + 1, sizeof(char));
	if (new_s == (void *)0)
		return ((void *)0);
	ft_strlcpy(new_s, s1, size_s1 + 1);
	ft_strlcat(new_s, s2, size_s1 + size_s2 + 1);
	return (new_s);
}
