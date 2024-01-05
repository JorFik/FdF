/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 21:18:05 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/05 17:57:18 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	mlx_t	*fdf_mlx;
	mlx_image_t	*image;

	if (argc != 2)
		return (ft_printf("Usage: ./fdf <filename>.fdf\n"), 0);
	argv[0] = NULL;
	if (!(fdf_mlx = mlx_init(600, 600, "MLX42", true)))
		return (ft_printf("%s\n", mlx_strerror(mlx_errno)), 1);
	if (!(image = mlx_new_image(fdf_mlx, 600, 600)))
	{
		mlx_close_window(fdf_mlx);
		return (ft_printf("%s\n", mlx_strerror(mlx_errno)), 1);
	}
	if (mlx_image_to_window(fdf_mlx, image, 0, 0) == -1)
	{
		mlx_close_window(fdf_mlx);
		return (ft_printf("%s\n", mlx_strerror(mlx_errno)), 1);
	}
	mlx_terminate(fdf_mlx);
	return (0);
}
