/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:48:16 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/16 21:57:32 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_jmpspc(char *s)
{
	while ((*s == ' ' || (*s >= 9 && *s <= 13)) && *s)
		s++;
	return (s);
}

static char	*ft_jmpsign(char *s)
{
	if ((*s == '-' || *s == '+') && *s)
		s ++;
	return (s);
}

static int	ft_sign(char *s)
{
	int	counter;

	counter = 0;
	while ((*s == ' ' || *s == '-' || *s == '+' || (*s >= 9 && *s <= 13)) && *s)
	{
		if (*s == ' ' || *s == '+' || (*s >= 9 && *s <= 13))
			s++;
		if (*s == '-')
			counter++;
		if (*s == '-')
			s++;
	}
	if (counter % 2)
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	char	*s;
	int		new_n_shiny_usable_int;
	int		sign;
	int		i;

	i = 0;
	new_n_shiny_usable_int = 0;
	sign = ft_sign((char *)str);
	s = ft_jmpsign(ft_jmpspc((char *)str));
	while (s[i] && s[i] >= 48 && s[i] <= 57)
	{
		new_n_shiny_usable_int *= 10;
		new_n_shiny_usable_int += (int)s[i] - 48;
		i++;
	}
	return (new_n_shiny_usable_int * sign);
}
