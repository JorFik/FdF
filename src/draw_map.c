/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:46:16 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/31 20:40:19 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	get_y(const int x, const int y, t_map *map)
{
	const float	middle = map->drawn_map->height / 2;
	const int	scale = map->scale;
	const int	iso_y = scale * y * map->param;
	const int	iso_x = scale * x;

	return (((iso_y - iso_x) / map->param) + middle
		- (map->z_value[y][x] * scale / 2));
}

static float	get_x(const int x, const int y, t_map *map)
{
	const int	scale = map->scale;
	const int	iso_y = scale * y / map->param;
	const int	iso_x = scale * x;

	return ((iso_y + iso_x) / map->param);
}

static void	get_size(t_map *map)
{
	int			max_z;
	int			min_z;
	uint32_t	x;
	uint32_t	y;
	int			z;

	y = -1;
	max_z = 0;
	min_z = 0;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			z = map->z_value[y][x];
			if (z > max_z)
				max_z = z;
			if (z < min_z)
				min_z = z;
		}
	}
	map->size[H] = (abs(max_z - min_z) + map->height
			+ map->width) * map->scale;
	map->size[W] = (map->width + map->height) * map->scale;
}

static void	connect_map(t_map *map)
{
	uint32_t			x;
	uint32_t			y;
	const mlx_image_t	*img = (const mlx_image_t *)map->drawn_map;
	const int			**color = (const int **)map->colors;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x + 1 < map->width)
				draw_line(img, (int [2]){get_x(x, y, map), get_y(x, y, map)},
					(int [2]){get_x(x + 1, y, map), get_y(x + 1, y, map)},
					(int [2]){color[y][x], color[y][x + 1]});
			if (y + 1 < map->height)
				draw_line(img, (int [2]){get_x(x, y, map), get_y(x, y, map)},
					(int [2]){get_x(x, y + 1, map), get_y(x, y + 1, map)},
					(int [2]){color[y][x], color[y + 1][x]});
			x++;
		}
		y++;
	}
}

void	plot_map(t_map *map)
{
	uint32_t	x;
	uint32_t	y;
	int			check;

	if (map->drawn_map)
		mlx_delete_image(map->fdf, map->drawn_map);
	get_size(map);
	map->drawn_map = mlx_new_image(map->fdf, map->size[W], map->size[H]);
	exit_on_error(CHECK_NULL, map->drawn_map, "Error creating map image", map);
	check = mlx_image_to_window(map->fdf, map->drawn_map, (WIDTH / 2)
			- map->size[W] / 4, (HEIGHT - map->size[H]) / 2);
	exit_on_error(check, NULL, "Error setting iso view in window", map);
	connect_map(map);
}

//_ punto A es la funcion para las coordenadas
//_ https://www.geogebra.org/calculator/bmcd6ftk