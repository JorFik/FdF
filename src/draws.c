/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:32:27 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/31 20:53:52 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(const mlx_image_t *img, int x, int y, int color)
{
	mlx_image_t	*image;

	image = (mlx_image_t *)img;
	if (is_coord_valid((int []){x, y}, img))
		mlx_put_pixel(image, x, y, color);
}

static void	draw_straight(const mlx_image_t *img, int *start, int *final,
		int color[2])
{
	double	*c_shift;
	int		i;

	i = -1;
	if (start[0] != final[0] && start[1] != final[1])
		return ;
	if (start[1] > final[1] || start[0] > final[0])
		return (draw_straight(img, final, start, color));
	c_shift = color_shift(color[0], color[1], start, final);
	while (++i + start[1] <= final[1] && start[0] == final[0])
		put_pixel(img, start[0], start[1] + i, set_color(c_shift, i, *color));
	while (++i + start[0] <= final[0] && start[1] == final[1])
		put_pixel(img, start[0] + i, start[1], set_color(c_shift, i, *color));
	ft_free_n_null((void **)&c_shift);
}

void	draw_line(const mlx_image_t *img, int start[2], int end[2],
		int color[2])
{
	double	*c_shift;
	float	slope;
	float	y;
	float	i;

	if (start[0] > end[0])
		return (draw_line(img, end, start, (int [2]){color[1], color[0]}));
	if (start[0] == end[0] || start[1] == end[1])
		return (draw_straight(img, start, end, color));
	c_shift = color_shift(color[0], color[1], start, end);
	y = start[1];
	slope = (float)(end[1] - start[1]) / (end[0] - start[0]);
	while (*start <= end[0])
	{
		i = 1;
		while (--i > slope && slope < 0 && y + i >= end[1])
			put_pixel(img, *start, y + i, set_color(c_shift, fabs(i), *color));
		*color = set_color(c_shift, fabs(i), *color);
		while (i++ < slope && slope > 0 && y + i <= end[1] && i >= 0)
			put_pixel(img, *start, y + i, set_color(c_shift, i, *color));
		*color = set_color(c_shift, i, *color);
		y += slope;
		*start += 1;
	}
	ft_free_n_null((void **)&c_shift);
}

void	draw_ft(mlx_image_t *img, float (ft)(float, void *), int x[2],
	t_map *map)
{
	const int	start = 0;
	const int	final = 1;
	const int	color = 0x00FFFF88;
	int			y[2];

	while (x[start] < x[final])
	{
		y[0] = ft(x[0], &map->param);
		y[1] = ft(x[0] + 1, &map->param);
		draw_line(img, (int []){x[0], y[0]}, (int []){x[0] + 1, y[1]},
			(int [2]){color, color});
		x[0]++;
	}
}
