/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:16:08 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/30 12:24:24 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_rgba(int r, int g, int b, int a)
{
	int	rgba;

	r = r << 24;
	g = g << 16;
	b = b << 8;
	rgba = r | g | b | a;
	return (rgba);
}

int	get_r(int rgba)
{
	const int	r = (rgba >> 24) & 0xFF;

	return (r);
}

// Get the green channel.
int	get_g(int rgba)
{
	const int	g = (rgba >> 16) & 0xFF;

	return (g);
}

// Get the blue channel.
int	get_b(int rgba)
{
	const int	b = (rgba >> 8) & 0xFF;

	return (b);
}

// Get the alpha channel.
int	get_a(int rgba)
{
	const int	a = rgba & 0xFF;

	return (a);
}
