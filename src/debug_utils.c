/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:23:47 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/25 17:18:53 by JFikents         ###   ########.fr       */
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
	int			*aperture;
	static int	move = -640;
	static int	flag = 0;
	const int	middle = WIDTH / 2;

	aperture = (int *)param;
	if (move == 650)
		move = -640;
	if (x != 0 && !flag)
		flag = 1;
	if (x == 0 && flag)
	{
		move += 10;
		flag = 0;
	}
	return (-((fabs(x - middle - move) / *aperture)
			+ fabs((float) move / *aperture)) + HEIGHT);
}

void	handle_grid(mlx_key_data_t keydata, void *param)
{
	t_map		*map;
	int			*aperture;

	map = (t_map *)param;
	aperture = (int *)map->param;
	ft_printf("aperture: %d\n", *aperture);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		map->grid->enabled = !map->grid->enabled;
	if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
	{
		*aperture += 1;
		mlx_delete_image(map->fdf, map->grid);
		map->grid = draw_axis(map);
	}
	if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
	{
		if (*aperture > 1)
			*aperture -= 1;
		mlx_delete_image(map->fdf, map->grid);
		map->grid = draw_axis(map);
	}
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
		x += 2;
	}
	draw_line(line, (int []){line->width / 2, line->height - 1},
		(int []){line->width / 2, 0}, (int [2]) {0x00FFFFFF, 0xFF0000FF});
	return (line);
}
