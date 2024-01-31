/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_parallel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:34:49 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/31 20:41:33 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static float	get_y(const int x, const int y, t_map *map)
{
	return (y * map->scale);
}

static float	get_x(const int x, const int y, t_map *map)
{
	return (x * map->scale);
}

static void	get_size(t_map *map)
{
	map->size[H] = map->height * map->scale;
	map->size[W] = map->width * map->scale;
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

void	plot_map_parallel(t_map *map)
{
	int		check;

	if (map->drawn_map)
		mlx_delete_image(map->fdf, map->drawn_map);
	get_size(map);
	map->drawn_map = mlx_new_image(map->fdf, map->size[W], map->size[H]);
	exit_on_error(CHECK_NULL, map->drawn_map, "Error create parallel map", map);
	check = mlx_image_to_window(map->fdf, map->drawn_map, 0, 0);
	exit_on_error(check, NULL, "Error setting parallel map in window", map);
	connect_map(map);
}
