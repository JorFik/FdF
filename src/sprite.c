/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:08:28 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/09 22:25:57 by JFikents         ###   ########.fr       */
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

void	part_1_mario(mlx_image_t *mario)
{
	int	yellow;
	int	blue;
	int	red;

	red = get_rgba(224, 26, 26, 255);
	blue = get_rgba(94, 101, 231, 255);
	yellow = get_rgba(255, 181, 0, 255);
	print_line(mario, 0, 12, 12, yellow);
	print_line(mario, 0, 11, 12, yellow);
	print_line(mario, 0, 10, 12, yellow);
	print_line(mario, 3, 6, 7, yellow);
	print_line(mario, 3, 5, 7, yellow);
	print_line(mario, 2, 4, 10, yellow);
	print_line(mario, 2, 3, 9, yellow);
	print_line(mario, 5, 2, 4, yellow);
	print_line(mario, 4, 0, 5, red);
	print_line(mario, 2, 10, 8, red);
	print_line(mario, 0, 9, 12, red);
	print_line(mario, 1, 8, 10, red);
	print_line(mario, 2, 7, 6, red);
	print_line(mario, 3, 1, 9, red);
	print_line(mario, 2, 13, 3, blue);
	print_line(mario, 7, 13, 3, blue);
	print_line(mario, 2, 12, 8, blue);
}

void	part_2_mario(mlx_image_t *mario)
{
	int	blue;
	int	brown;

	brown = get_rgba(94, 24, 24, 255);
	blue = get_rgba(94, 101, 231, 255);
	print_line(mario, 3, 11, 6, blue);
	print_line(mario, 3, 10, 6, blue);
	print_line(mario, 4, 9, 4, blue);
	print_line(mario, 4, 8, 1, blue);
	print_line(mario, 7, 8, 1, blue);
	print_line(mario, 4, 7, 1, blue);
	print_line(mario, 4, 10, 1, get_rgba(255, 181, 0, 255));
	print_line(mario, 7, 10, 1, get_rgba(255, 181, 0, 255));
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

mlx_image_t	*mario_bros(mlx_t *window)
{
	mlx_image_t	*mario;
	int			black;

	black = get_rgba(0, 0, 0, 255);
	mario = mlx_new_image(window, 12, 16);
	exit_on_error(CHECK_NULL, mario, NULL, window);
	exit_on_error(mlx_image_to_window(window, mario, WIDTH / 2, HEIGHT / 2),
		NULL, NULL, window);
	exit_on_error(mlx_image_to_window(window, mario, WIDTH / 3, HEIGHT / 2),
		NULL, NULL, window);
	part_1_mario(mario);
	part_2_mario(mario);
	print_line(mario, 7, 5, 4, black);
	print_line(mario, 8, 4, 1, black);
	print_line(mario, 7, 3, 1, black);
	print_line(mario, 7, 2, 1, black);
	return (mario);
}

mlx_image_t	*draw_star(mlx_t *fdf)
{
	mlx_image_t	*line;

	line = mlx_new_image(fdf, 100, 100);
	exit_on_error(CHECK_NULL, line, NULL, fdf);
	exit_on_error(mlx_image_to_window(fdf, line, (WIDTH - line->width) / 2,
			(HEIGHT - line->height) / 2), NULL, NULL, fdf);
	draw_line(line, (int []){line->width / 4, 0}, (int []){line->width / 2,
		line->height - 1}, 16711935);
	draw_line(line, (int []){line->width / 2, line->height - 1},
		(int []){line->width / 4 * 3, 0}, 16711935);
	draw_line(line, (int []){line->width / 4 * 3, 0},
		(int []){0, line->height / 4 * 3}, 16711935);
	draw_line(line, (int []){0, line->height / 4 * 3},
		(int []){line->width - 1, line->height / 4 * 3}, 16711935);
	draw_line(line, (int []){line->width - 1, line->height / 3 * 2},
		(int []){0, line->height / 3 * 2}, 16711935);
	draw_line(line, (int []){line->width - 1, line->height / 4 * 3},
		(int []){line->width / 4, 0}, 16711935);
	return (line);
}
