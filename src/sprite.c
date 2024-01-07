/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:08:28 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/07 23:39:21 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_line(mlx_image_t *image, int x, int y, int length, int color)
{
	int	i;

	i = -1;
	while (++i != length)
		mlx_put_pixel(image, x + i, y, color);
}

void	yellow_mario(mlx_image_t *mario)
{
	int	yellow;

	yellow = get_rgba(255, 181, 0, 255);
	print_line(mario, 0, 12, 12, yellow);
	print_line(mario, 0, 11, 12, yellow);
	print_line(mario, 0, 10, 12, yellow);
	print_line(mario, 3, 6, 7, yellow);
	print_line(mario, 3, 5, 7, yellow);
	print_line(mario, 2, 4, 10, yellow);
	print_line(mario, 2, 3, 9, yellow);
	print_line(mario, 5, 2, 4, yellow);
}

void	blue_mario(mlx_image_t *mario)
{
	int	blue;

	blue = get_rgba(94, 101, 231, 255);
	print_line(mario, 2, 13, 3, blue);
	print_line(mario, 7, 13, 3, blue);
	print_line(mario, 2, 12, 8, blue);
	print_line(mario, 3, 11, 6, blue);
	print_line(mario, 3, 10, 6, blue);
	print_line(mario, 4, 9, 4, blue);
	print_line(mario, 4, 8, 1, blue);
	print_line(mario, 7, 8, 1, blue);
	print_line(mario, 4, 7, 1, blue);
}

void	red_mario(mlx_image_t *mario)
{
	int	red;

	red = get_rgba(224, 26, 26, 255);
	print_line(mario, 4, 0, 5, red);
	print_line(mario, 2, 10, 8, red);
	print_line(mario, 0, 9, 12, red);
	print_line(mario, 1, 8, 10, red);
	print_line(mario, 2, 7, 6, red);
	print_line(mario, 3, 1, 9, red);
}

void	brown_mario(mlx_image_t *mario)
{
	int	brown;

	brown = get_rgba(94, 24, 24, 255);
	print_line(mario, 0, 15, 4, brown);
	print_line(mario, 8, 15, 4, brown);
	print_line(mario, 1, 14, 3, brown);
	print_line(mario, 8, 14, 3, brown);
	print_line(mario, 1, 5, 2, brown);
	print_line(mario, 1, 4, 1, brown);
	print_line(mario, 3, 4, 2, brown);
	print_line(mario, 1, 3, 1, brown);
	print_line(mario, 3, 3, 1, brown);
	print_line(mario, 2, 2, 3, brown);
}

void	black_mario(mlx_image_t *mario)
{
	int	black;

	black = get_rgba(0, 0, 0, 255);
	print_line(mario, 7, 5, 4, black);
	print_line(mario, 8, 4, 1, black);
	print_line(mario, 7, 3, 1, black);
	print_line(mario, 7, 2, 1, black);
}

mlx_image_t	*mario_bros(mlx_t *window)
{
	mlx_image_t	*mario;

	mario = mlx_new_image(window, 12, 16);
	exit_on_error(CHECK_NULL, mario, NULL, window);
	exit_on_error(mlx_image_to_window(window, mario, WIDTH / 2, HEIGHT / 2),
		NULL, NULL, window);
	yellow_mario(mario);
	red_mario(mario);
	blue_mario(mario);
	print_line(mario, 4, 10, 1, get_rgba(255, 181, 0, 255));
	print_line(mario, 7, 10, 1, get_rgba(255, 181, 0, 255));
	brown_mario(mario);
	black_mario(mario);
	return (mario);
}
