/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:30:41 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/10 01:59:45 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	if (str)
	{
		while (*(str + counter) != '\0')
			counter ++;
	}
	return (counter);
}
