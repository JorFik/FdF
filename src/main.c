/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 21:18:05 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/10 23:27:59 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	x_square_root(float x)
{
	return (sqrtf(1 - (x * x) + (1000 * x)));
}
	// return (x * sin(x / 390));

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
	mlx_image_t	*mario;

	mario = (mlx_image_t *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT
		&& mario->instances->y > 0)
		mario->instances->y -= 1;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT
		&& mario->instances->y < HEIGHT - (int) mario->height)
		mario->instances->y += 1;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT
		&& mario->instances->x > 0)
		mario->instances->x -= 1;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT
		&& mario->instances->x < WIDTH - (int) mario->width)
		mario->instances->x += 1;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_REPEAT
		&& mario->instances[1].y > 0)
		mario->instances[1].y -= 1;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_REPEAT
		&& mario->instances[1].y < HEIGHT - (int) mario->height)
		mario->instances[1].y += 1;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT
		&& mario->instances[1].x > 0)
		mario->instances[1].x -= 1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT
		&& mario->instances[1].x < WIDTH - (int) mario->width)
		mario->instances[1].x += 1;
	if (keydata.key == MLX_KEY_B && keydata.action == MLX_PRESS)
		mlx_resize_image(mario, mario->width * 2, mario->height * 2);
	else if (keydata.key == MLX_KEY_N && keydata.action == MLX_PRESS)
		mlx_resize_image(mario, mario->width / 2, mario->height / 2);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
		ft_printf("%d\n", mario->count);
}

void	set_background(mlx_image_t *background)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			mlx_put_pixel(background, x++, y, get_rgba(0, 0, 0, 255));
		y ++;
	}
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
		if (coordinate_y > HEIGHT)
			coordinate_y = HEIGHT - 1;
		mlx_put_pixel(param, 50, coordinate_y, 0xFF0000FF);
		mlx_put_pixel(param, 50, ++coordinate_y, 0xFF0000FF);
		delta_y --;
	}
}

int	main(int argc, char **argv)
{
	mlx_image_t	*background;
	mlx_t		*fdf;
	mlx_image_t	*axis;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf <filename>.fdf\n"), 0);
	argv[0] = NULL;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	fdf = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	mlx_set_window_title(fdf, "FdF");
	exit_on_error(CHECK_NULL, (void *)fdf, NULL, fdf);
	background = mlx_new_image(fdf, WIDTH, HEIGHT);
	exit_on_error(CHECK_NULL, background, NULL, fdf);
	set_background(background);
	exit_on_error(mlx_image_to_window(fdf, background, 0, 0), NULL, NULL, fdf);
	axis = draw_axis(fdf);
	draw_with_function(axis, x_square_root, (int [2][2]){{0, 1},
	{1000, (int) x_square_root(1000)}}, get_rgba(255, 0, 0, 255));
	mlx_scroll_hook(fdf, scroll_hook, background);
	mlx_key_hook(fdf, key_hook, axis);
	mlx_loop_hook(fdf, key_press, (void *)fdf);
	mlx_loop(fdf);
	mlx_terminate(fdf);
	return (0);
}
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