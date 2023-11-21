/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:46:56 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/09 15:34:21 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(char *src, int c)
{
	int		i;
	char	busco;

	busco = (char) c;
	i = 0;
	while (src[i] != busco && src[i])
		i ++;
	if (src[i] == busco)
		return (&src[i]);
	else
		return (0);
}

// int	main(int argc, char **argv)
// {
// 	if (argc > 2)
// 	{
// 		printf("Estas buscando %c en %s\n", argv[2][0], argv[1]);
// 		if (ft_strchr(argv[1], argv[2][0]))
// 			printf("Encontre %s", ft_strchr(argv[1], argv[2][0]));
// 		else
// 			printf("No encontre nada");
// 	}
// 	return (0);
// }
