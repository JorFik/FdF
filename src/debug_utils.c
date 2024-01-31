/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:23:47 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/31 17:01:27 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_map *map)
{
	uint32_t	y;
	uint32_t	x;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			ft_printf("%d,%p ", map->z_value[y][x], map->colors[y][x]);
		ft_printf("\n");
	}
}

float	draw_grid(float x, void *param)
{
	const int	aperture = (int)param;
	static int	move = -640;
	static int	flag = 0;
	const int	middle = WIDTH / 2;

	if (move == 650)
		move = -640;
	if (x != 0 && !flag)
		flag = 1;
	if (x == 0 && flag)
	{
		move += 10;
		flag = 0;
	}
	return (-((fabs(x - middle - move) / aperture)
			+ fabs((float) move / aperture)) + HEIGHT);
}

mlx_image_t	*draw_axis(t_map *map)
{
	mlx_image_t	*line;
	uint32_t	x;

	line = mlx_new_image(map->fdf, WIDTH, HEIGHT);
	exit_on_error(CHECK_NULL, line, NULL, map);
	exit_on_error(mlx_image_to_window(map->fdf, line, (WIDTH - line->width) / 2,
			(HEIGHT - line->height) / 2), NULL, NULL, map);
	x = 0;
	while (x <= line->width)
	{
		draw_ft(line, draw_grid, (int [2]){0, WIDTH}, map);
		x += 10;
	}
	draw_line(line, (int []){line->width / 2, line->height - 1},
		(int []){line->width / 2, 0}, (int [2]){0x0000FF88, 0xFF000088});
	return (line);
}

int	is_coord_valid(int *xy, const mlx_image_t *image)
{
	uint32_t	x;
	uint32_t	y;

	x = *xy;
	y = xy[1];
	if (x < 0 || x >= image->width || y < 0 || y >= image->height)
		return (0);
	return (1);
}
