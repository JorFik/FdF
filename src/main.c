/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 21:18:05 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/13 13:22:15 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//! EREASE system("leaks fdf"); in EXIT_ON_ERROR
void	key_press(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{
		mlx_terminate((mlx_t *)param);
		exit(0);
	}
}

//! EREASE system("leaks fdf"); in EXIT_ON_ERROR
mlx_image_t	*set_background(t_map *map)
{
	mlx_image_t	*background;
	int			x;
	int			y;

	y = 0;
	background = mlx_new_image(map->fdf, WIDTH, HEIGHT);
	exit_on_error(CHECK_NULL, background, NULL, map);
	exit_on_error(mlx_image_to_window(map->fdf, background, 0, 0), NULL, NULL,
		map);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			mlx_put_pixel(background, x++, y, get_rgba(0, 0, 0, 255));
		y ++;
	}
	return (background);
}

//! EREASE system("leaks fdf"); in EXIT_ON_ERROR
t_map	*map_initializer(void)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	exit_on_error(CHECK_NULL, (void *)map, "Error allocating t_map", map);
	map->z_value = NULL;
	map->colors = NULL;
	map->width = 0;
	map->height = 0;
	map->fdf = NULL;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	map->fdf = mlx_init(WIDTH, HEIGHT, "FdF", true);
	exit_on_error(CHECK_NULL, (void *)map->fdf, NULL, map);
	return (map);
}

//! EREASE system("leaks fdf"); in EXIT_ON_ERROR
int	main(int argc, char **argv)
{
	mlx_image_t	*background;
	mlx_image_t	*axis;
	t_map		*map;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf <filename>.fdf\n"), 0);
	map = map_initializer();
	read_map(argv[1], map);
	background = set_background(map);
	axis = draw_axis(map);
	mlx_loop_hook(map->fdf, key_press, (void *)map->fdf);
	mlx_loop(map->fdf);
	mlx_terminate(map->fdf);
	return (0);
}
//! EREASE system("leaks fdf"); in EXIT_ON_ERROR
	// draw_with_function(axis, x_square_root, (int [2][2]){{0, 1},
	// {1000, (int) x_square_root(1000)}}, get_rgba(255, 0, 0, 255));
	// mlx_scroll_hook(fdf, scroll_hook, background);
	// mlx_key_hook(fdf, key_hook, axis);
	// mlx_image_t	*mario;

	// mario = mario_bros(fdf);
	// mlx_key_hook(fdf, key_hook, mario);
/*
_	MLX_STRETCH_IMAGE = 0,
		Should images resize with the window as it's being resized or not. 
		Default: false
_	MLX_FULLSCREEN,			
		Should the window be in Fullscreen, note it will fullscreen at the given
		resolution.
		Default: false
_	MLX_MAXIMIZED,			
		Start the window in a maximized state, overwrites the fullscreen state
		if this is true.
		Default: false
_	MLX_DECORATED,			
		Have the window be decorated with a window bar.
		Default: true
_	MLX_HEADLESS,			
		Run in headless mode, no window is created. (NOTE: Still requires some
		form of window manager such as xvfb)
_	MLX_SETTINGS_MAX
		Setting count.
*/