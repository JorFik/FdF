/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 19:39:13 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/31 19:57:43 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	refresh_map(t_map *map)
{
	if (map->parallel)
		plot_map_parallel(map);
	else
		plot_map(map);
}

void	key_press(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{
		mlx_terminate((mlx_t *)param);
		exit(0);
	}
}

void	handle_move(mlx_key_data_t keydata, t_map *map)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		map->drawn_map->instances->y -= 10;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		map->drawn_map->instances->y += 10;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		map->drawn_map->instances->x -= 10;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		map->drawn_map->instances->x += 10;
}

void	handle_zoom(mlx_key_data_t keydata, t_map *map)
{
	static int	scale = 1;

	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		scale = 1;
		map->scale = scale;
		map->param = 2;
		refresh_map(map);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		if (map->scale < 14)
			map->scale = ++scale;
		refresh_map(map);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		if (map->scale > 1)
			map->scale = --scale;
		refresh_map(map);
	}
	handle_move(keydata, map);
}

void	handle_grid(mlx_key_data_t keydata, void *param)
{
	t_map		*map;

	map = (t_map *)param;
	handle_zoom(keydata, map);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		map->param += 1;
		refresh_map(map);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		if (map->param > 1)
			map->param -= 1;
		refresh_map(map);
	}
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
	{
		map->parallel = !map->parallel;
		refresh_map(map);
	}
}
