/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:32:27 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/09 22:10:53 by JFikents         ###   ########.fr       */
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
		while (++i != final[1])
			mlx_put_pixel(image, origin[0], origin[1] + i, color);
		return ;
	}
	if (origin[1] == final[1])
	{
		if (origin[0] > final[0])
			draw_straight(image, final, origin, color);
		while (++i != final[0])
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

void	draw_line(mlx_image_t *image, int *xy_1, int *xy_2, int color)
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
