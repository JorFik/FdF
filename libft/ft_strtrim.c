/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:13:39 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/12 21:34:12 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*new_s;
	unsigned long	s_s1;
	unsigned long	cut_s;
	unsigned long	cut_e;

	s_s1 = ft_strlen(s1);
	cut_s = 0;
	cut_e = 0;
	if (!*s1)
		return (new_s = ft_calloc(1, sizeof(char)));
	if (!*set)
		return (ft_strdup(s1));
	while (ft_strchr((char *)set, s1[cut_s]) && s1[cut_s])
		cut_s ++;
	while (ft_strrchr((char *)set, s1[s_s1 - cut_e - 1])
		&& s_s1 - cut_e - 1 > cut_s)
		cut_e ++;
	new_s = malloc ((s_s1 - cut_e - cut_s + 1) * sizeof(char));
	if (new_s == (void *)0)
		return (new_s);
	ft_strlcpy(new_s, ((char *)s1 + cut_s), (s_s1 - cut_e - cut_s + 1));
	return (new_s);
}
