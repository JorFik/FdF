/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 21:37:17 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/16 22:16:44 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_wcount(char *s, char c)
{
	unsigned long	counter;

	counter = 0;
	while (*s == c && *s)
		s ++;
	while (*s)
	{
		while (*s == c && *s)
			s ++;
		while (*s != c && *s)
			s ++;
		counter ++;
		while (*s == c && *s)
			s ++;
	}
	return (counter);
}

static int	ft_protect_malloc(char **pop, unsigned long i)
{
	if (!pop[i])
	{
		while (i--)
			free(pop[i]);
		free(pop);
		return (0);
	}
	return (1);
}

char	**ft_split(char *s, char c)
{
	char			**pop;
	unsigned long	wcount;
	unsigned long	i;

	i = 0;
	wcount = ft_wcount(s, c);
	pop = ft_calloc(wcount + 1, sizeof(char *));
	if (!pop)
		return (0);
	while (*s && wcount > i)
	{
		while (*s == c && *s)
			s++;
		pop[i] = ft_substr(s, 0, (unsigned long)(ft_strchr(s, c) - s));
		if (!ft_protect_malloc(pop, i))
			return (0);
		while (*s != c && *s)
			s ++;
		i ++;
	}
	return (pop);
}
