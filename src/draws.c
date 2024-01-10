/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:32:27 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/10 23:00:03 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_straight(mlx_image_t *image, int *origin, int *final, int color)
{
	int	i;

	i = -1;
	if (origin[0] == final[0])
	{
		if (origin[1] > final[1])
			draw_straight(image, final, origin, color);
		else
			while (++i + origin[1] != final[1])
				mlx_put_pixel(image, origin[0], origin[1] + i, color);
		return ;
	}
	else if (origin[1] == final[1])
	{
		if (origin[0] > final[0])
			draw_straight(image, final, origin, color);
		else
			while (++i + origin[0] != final[0])
				mlx_put_pixel(image, origin[0] + i, origin[1], color);
		return ;
	}
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

void	draw_line(mlx_image_t *image, int xy_1[2], int xy_2[2], int color)
{
	float	slope;
	float	x;
	float	y;
	int		move_y;

	x = xy_1[0] + 1;
	y = xy_1[1];
	slope = 0;
	if (!(is_coord_valid(xy_1, image) || is_coord_valid(xy_2, image)))
		return ;
	if (xy_1[0] != xy_2[0])
		slope = (float)(xy_2[1] - xy_1[1]) / abs(xy_2[0] - xy_1[0]);
	while (y < xy_2[1] && --x >= 0)
	{
		move_y = y;
		while (move_y < y + slope && is_coord_valid((int []){x, move_y}, image))
			mlx_put_pixel(image, x, move_y++, color);
		if ((xy_2[0] - xy_1[0]) > 0)
			x += 2;
		y += slope;
	}
	draw_straight(image, xy_1, xy_2, color);
	if (xy_2[1] - xy_1[1] < 0)
		draw_line(image, xy_2, xy_1, color);
}

mlx_image_t	*draw_axis(mlx_t *fdf)
{
	mlx_image_t	*line;

	line = mlx_new_image(fdf, WIDTH, HEIGHT);
	exit_on_error(CHECK_NULL, line, NULL, fdf);
	exit_on_error(mlx_image_to_window(fdf, line, (WIDTH - line->width) / 2,
			(HEIGHT - line->height) / 2), NULL, NULL, fdf);
	draw_line(line, (int []){line->width / 2, line->height - 1},
		(int []){0, line->width * tan(60)}, 16711935);
	draw_line(line, (int []){line->width / 2, line->height - 1},
		(int []){line->width - 1, line->width * tan(60)}, 16711935);
	draw_line(line, (int []){line->width / 2, line->height - 1},
		(int []){line->width / 2, 0}, 16711935);
	return (line);
}

void	draw_with_function(mlx_image_t *img, float (function)(float),
	int xy[2][2], int color)
{
	const int	x = 0;
	const int	y = 1;
	const int	start = 0;
	const int	final = 1;

	if ((int) ceil(function(xy[final][x])) != xy[final][y]
		|| !is_coord_valid(xy[start], img) || !is_coord_valid(xy[final], img))
		return ;
	while (xy[start][x] != xy[final][x] && xy[start][x] <= xy[final][x])
	{
		if (is_coord_valid((int []){xy[start][x], function(xy[start][x])},
			img))
		{
			mlx_put_pixel(img, xy[start][x], function(xy[start][x]),
				color);
			if (is_coord_valid((int []){xy[start][x] + 1,
				function(xy[start][x] + 1)}, img))
				draw_line(img, (int []){xy[start][x],
					(int) function(xy[start][x])}, (int []){xy[start][x] + 1,
					(int) function(xy[start][x] + 1)}, color);
		}
		xy[start][x]++;
	}
}
