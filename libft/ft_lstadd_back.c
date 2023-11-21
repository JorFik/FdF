/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:16:23 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/17 18:04:52 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **header, t_list *new)
{
	t_list	*tmp;

	tmp = ft_lstlast(*header);
	if (!tmp)
		*header = new;
	else
		tmp->next = new;
	return ;
}
