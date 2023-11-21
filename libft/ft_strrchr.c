/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:35:49 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/16 22:30:19 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *src, int c)
{
	int		i;
	char	busco;

	busco = (char) c;
	i = ft_strlen(src);
	while ((i >= 0) && src[i] != busco)
		i --;
	if (i < 0)
		return (0);
	if (src[i] == busco)
		return (&src[i]);
	else
		return (0);
}
