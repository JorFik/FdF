/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:51:35 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/11 15:03:40 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(unsigned long count, unsigned long size)
{
	void			*new_p;
	unsigned long	i;

	i = 0;
	new_p = malloc(count * size);
	if (new_p == NULL)
		return (NULL);
	while ((count * size) > i)
	{
		((char *)new_p)[i] = 0;
		i ++;
	}
	return (new_p);
}
