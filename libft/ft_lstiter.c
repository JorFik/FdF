/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:25:52 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/17 22:34:54 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*actual;
	t_list	*tmp;

	actual = lst;
	if (!actual || !f)
		return ;
	while (actual)
	{
		tmp = actual->next;
		f(actual->content);
		actual = tmp;
	}
	return ;
}
