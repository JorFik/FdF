/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:32:27 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/25 17:50:58 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(mlx_image_t *image, int x, int y, int color)
{
	if (is_coord_valid((int []){x, y}, image))
		mlx_put_pixel(image, x, y, color);
}

void	draw_straight(mlx_image_t *image, int *start, int *final, int color[2])
{
	int		i;
	float	delta_c;

	delta_c = 0;
	i = -1;
	if (start[0] != final[0] && start[1] != final[1])
		return ;
	if (start[1] > final[1] || start[0] > final[0])
		return (draw_straight(image, final, start, color));
	if (start[0] == final[0])
	{
		delta_c = (float)(color[1] - color[0]) / abs(final[1] - start[1]);
		while (++i + start[1] != final[1])
			put_pixel(image, start[0], start[1] + i, color[0] + (delta_c * i));
		return ;
	}
	if (start[0] != final[0])
		delta_c = (float)(color[1] - color[0]) / abs(final[0] - start[0]);
	while (++i + start[0] != final[0])
		put_pixel(image, start[0] + i, start[1], color[0] + (delta_c * i));
}

int	is_coord_valid(int *xy, mlx_image_t *image)
{
	uint32_t	x;
	uint32_t	y;

	x = *xy;
	y = xy[1];
	if (x < 0 || x >= image->width || y < 0 || y >= image->height)
		return (0);
	return (1);
}

void	draw_line(mlx_image_t *image, int start[2], int end[2], int color[2])
{
	float	slope;
	float	y;
	int		move_y;
	float	delta_c;


	if (start[1] > end[1])
		draw_line(image, end, start, color);
	y = start[1];
	slope = 0;
	delta_c = 0;
	if (start[0] != end[0])
		delta_c = (float)((color[1] - color[0]) / (end[0] - start[0]));
	if (start[0] != end[0])
		slope = (float)(end[1] - start[1]) / abs(end[0] - start[0]);
	while (y < end[1] && --*start >= 0 && *start < end[0])
	{
		move_y = -1;
		while (++move_y < slope)
			put_pixel(image, *start, y + move_y, color[0] + (delta_c * move_y));
		if ((end[0] - start[0]) > 0)
			*start += 2;
		y += slope;
	}
	draw_straight(image, start, end, color);
}

void	draw_ft(mlx_image_t *img, float (ft)(float, void *), int x[2],
	t_map *map)
{
	const int	start = 0;
	const int	final = 1;
	int			y[2];
	const int	color = 0x00FFFFFF;

	while (x[start] < x[final])
	{
		y[0] = ft(x[0], map->param);
		y[1] = ft(x[0] + 1, map->param);
		if (is_coord_valid((int []){x[0], y[0]}, img))
		{
			if (is_coord_valid((int []){x[0] + 1, y[1]}, img))
				draw_line(img, (int []){x[0], y[0]},
					(int []){x[0] + 1, y[1]},
					(int [2]){color, color});
		}
		x[0]++;
	}
}
