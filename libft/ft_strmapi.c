/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:20:46 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/16 12:39:37 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s);
	out = ft_calloc(size + 1, sizeof(char));
	if (!out)
		return (0);
	while (size > i && s[i])
	{
		out[i] = f(i, s[i]);
		i ++;
	}
	return (out);
}
