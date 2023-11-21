/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:40:16 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/16 22:14:59 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int car)
{
	if (ft_isalpha(car))
		return (1);
	if (ft_isdigit(car))
		return (2);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (!(argc == 2))
// 		return (0);
// 	printf ("Estas checando el caracter %c%c", argv[1][0], '\n');
// 	if (ft_isalnum (argv[1][0]) == 1)
// 		printf("Es Alpha");
// 	if (ft_isalnum (argv[1][0]) == 2)
// 		printf("Es Num");
// 	if (!ft_isalnum (argv[1][0]))
// 		printf("No e ninguno");
// 	return (0);
// }
