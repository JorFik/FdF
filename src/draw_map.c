/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:46:16 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/24 15:14:15 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_y(const int x, const int y, t_map *map)
{
	const int	aperture = *(int *)map->param;
	const float	middle = map->width / 2;

	return ((fabs(x - middle) / aperture) + map->z_value[y][x]);
}

void	plot_map(t_map *map)
{
	uint32_t	x;
	uint32_t	y;
	const int	middle = map->width / 2;

	map->drawn_map = mlx_new_image(map->fdf, map->width, map->height);
	exit_on_error(CHECK_NULL, map->drawn_map, NULL, map);
	exit_on_error(mlx_image_to_window(map->fdf, map->drawn_map,
			(WIDTH / 2) - middle, (HEIGHT - map->height) / 2), NULL, NULL, map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx_put_pixel(map->drawn_map, x + middle - y,
				get_y(x + middle, y, map) + y, map->colors[y][x]);
			x++;
		}
		y++;
	}
}

//_ punto A es la funcion para las coordenadas
//_ https://www.geogebra.org/calculator/bmcd6ftk