/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 21:18:05 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/07 23:39:40 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_press(void *param)
{
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{
		mlx_terminate((mlx_t *)param);
		exit(0);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	static int	x = 0;
	static int	y = 0;

	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT && y > 0)
	{
		mlx_put_pixel(param, x, --y, 0x0000FFFF);
		mlx_put_pixel(param, x, y + 1, 0x808000FF);
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT
		&& y < HEIGHT - 1)
	{
		mlx_put_pixel(param, x, ++y, 0x0000FFFF);
		mlx_put_pixel(param, x, y - 1, 0x808000FF);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT && x > 0)
	{
		mlx_put_pixel(param, --x, y, 0x0000FFFF);
		mlx_put_pixel(param, x + 1, y, 0x808000FF);
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT
		&& x < WIDTH - 1)
	{
		mlx_put_pixel(param, ++x, y, 0x0000FFFF);
		mlx_put_pixel(param, x - 1, y, 0x808000FF);
	}
}

void	background_hook(void *param)
{
	static int	x;
	static int	y;
	int			i;
	int			line_per_iteration;

	if (x == WIDTH)
	{
		x = 0;
		y ++;
	}
	if (y == HEIGHT + 1)
		return ;
	line_per_iteration = 0;
	i = 0;
	while (i < WIDTH - 1 && x + i < WIDTH)
		mlx_put_pixel(param, x + i++, y, 0x808000FF);
	x += i;
}

void	scroll_hook(double delta_x, double delta_y, void *param)
{
	static int	coordinate_y = 0;

	delta_x = 50;
	while (0 >= delta_y)
	{
		if (coordinate_y - 1 < 0)
			coordinate_y = 1;
		mlx_put_pixel(param, 50, coordinate_y, 0x000000FF);
		mlx_put_pixel(param, 50, --coordinate_y, 0x000000FF);
		delta_y ++;
		return ;
	}
	while (0 <= delta_y)
	{
		if (coordinate_y + 1 > HEIGHT)
			coordinate_y = HEIGHT - 1;
		mlx_put_pixel(param, 50, coordinate_y, 0xFF0000FF);
		mlx_put_pixel(param, 50, ++coordinate_y, 0xFF0000FF);
		delta_y --;
	}
}

int	main(int argc, char **argv)
{
	mlx_image_t	*image;
	mlx_t		*fdf;
	mlx_image_t	*mario;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf <filename>.fdf\n"), 0);
	argv[0] = NULL;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	fdf = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	mlx_set_window_title(fdf, "FdF");
	exit_on_error(CHECK_NULL, (void *)fdf, NULL, fdf);
	image = mlx_new_image(fdf, WIDTH, HEIGHT);
	exit_on_error(CHECK_NULL, image, NULL, fdf);
	exit_on_error(mlx_image_to_window(fdf, image, 0, 0), NULL, NULL, fdf);
	mario = mario_bros(fdf);
	mlx_scroll_hook(fdf, scroll_hook, image);
	mlx_key_hook(fdf, key_hook, image);
	mlx_loop_hook(fdf, key_press, (void *)fdf);
	mlx_loop_hook(fdf, background_hook, (void *)image);
	mlx_loop(fdf);
	mlx_terminate(fdf);
	return (0);
}

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