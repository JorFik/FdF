/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:29:43 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/09 13:31:01 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int car)
{
	if (car >= 48 && car <= 57)
		return (1);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (!(argc == 2))
// 		return (0);
// 	printf ("Estas checando la letra %c%c", argv[1][0], '\n');
// 	if (ft_isdigit (argv[1][0]))
// 		printf("Es");
// 	if (!ft_isdigit (argv[1][0]))
// 		printf("No es");
// 	return (0);
// }
