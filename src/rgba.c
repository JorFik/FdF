/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:31:45 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/31 20:08:19 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	*color_shift(int c_src, int c_end, int src[2], int end[2])
{
	const int	total_steps = abs(*end - *src) + abs(end[1] - src[1]);
	double		*rgba;

	rgba = (double *)ft_calloc(sizeof(double), 4);
	exit_on_error(CHECK_NULL, (void *)rgba, "Error allocating rgba", NULL);
	rgba[R] = (float)(get_r(c_end) - get_r(c_src)) / 2;
	rgba[G] = (float)(get_g(c_end) - get_g(c_src)) / 2;
	rgba[B] = (float)(get_b(c_end) - get_b(c_src)) / 2;
	rgba[A] = (float)(get_a(c_end) - get_a(c_src)) / 2;
	if (total_steps)
	{
		rgba[R] = (float)(get_r(c_end) - get_r(c_src)) / total_steps;
		rgba[G] = (float)(get_g(c_end) - get_g(c_src)) / total_steps;
		rgba[B] = (float)(get_b(c_end) - get_b(c_src)) / total_steps;
		rgba[A] = (float)(get_a(c_end) - get_a(c_src)) / total_steps;
	}
	return (rgba);
}

int	set_color(const double *c_shift, int i, int color)
{
	int	rgba[4];

	rgba[R] = get_r(color) + (c_shift[R] * i);
	rgba[G] = get_g(color) + (c_shift[G] * i);
	rgba[B] = get_b(color) + (c_shift[B] * i);
	rgba[A] = get_a(color) + (c_shift[A] * i);
	return (get_rgba(rgba[R], rgba[G], rgba[B], rgba[A]));
}
