/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:40:24 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/18 00:47:08 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*header;
	t_list			*tmp;
	void			*teeemp;

	header = NULL;
	while (lst)
	{
		teeemp = f(lst->content);
		tmp = ft_lstnew(teeemp);
		if (!tmp)
		{
			del(teeemp);
			ft_lstclear(&header, del);
			return (0);
		}
		ft_lstadd_back(&header, tmp);
		lst = lst->next;
	}
	return (header);
}
