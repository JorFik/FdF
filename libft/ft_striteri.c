/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:42:51 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/16 12:49:25 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s);
	while (size > i && s[i])
	{
		f(i, &s[i]);
		i ++;
	}
	return ;
}
