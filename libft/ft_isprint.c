/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:03:04 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/09 13:33:32 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int car)
{
	if (car >= 32 && car <= 126)
		return (1);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (!(argc == 2))
// 		return (0);
// 	printf ("Estas checando el caracter %c%c", argv[1][0], '\n');
// 	if (ft_isprint ('\0'))
// 		printf("Es");
// 	else
// 		printf("No es");
// 	return (0);
// }
