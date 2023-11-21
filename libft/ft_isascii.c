/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:50:57 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/09 13:33:26 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isascii(int car)
{
	if (car >= 0 && car <= 127)
		return (1);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (!(argc == 2))
// 		return (0);
// 	printf ("Estas checando el caracter %c%c", argv[1][0], '\n');
// 	if (ft_isascii (argv[1][0]) == 1)
// 		printf("Es Alpha");
// 	if (ft_isascii (argv[1][0]) == 2)
// 		printf("Es Num");
// 	if (!ft_isascii (argv[1][0]))
// 		printf("No es ninguno");
// 	return (0);
// }
