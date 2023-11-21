/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:11:25 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/10 20:26:16 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned long n)
{
	unsigned char	car;
	unsigned char	*s1;
	unsigned long	i;

	car = (unsigned char) c;
	s1 = (unsigned char *) s;
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != car && i < n - 1)
		i++;
	if (s1[i] == car)
		return (&s1[i]);
	return (0);
}
