/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:00:48 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/17 22:18:20 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **header, void (*del) (void *))
{
	t_list	*actual;
	t_list	*tmp;

	actual = *header;
	if (!header || !actual || !del)
		return ;
	while (actual)
	{
		tmp = actual->next;
		ft_lstdelone(actual, del);
		actual = tmp;
	}
	*header = NULL;
	return ;
}
