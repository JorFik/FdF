/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:27:34 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/31 20:21:09 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_2d_array(void ***array, int size)
{
	int	i;

	i = 0;
	while (size == -1 && (*array)[i])
		ft_free_n_null(&(array[0][i++]));
	while (size > 0 && i < size)
		ft_free_n_null(&(array[0][i++]));
	ft_free_n_null((void **)array);
}

void	exit_on_error(int status, void *check_4_null, char *error_message,
			t_map *map)
{
	if (status == -1 || (status == CHECK_NULL && !check_4_null))
	{
		if (error_message)
			perror(error_message);
		else
			perror(mlx_strerror(mlx_errno));
		if (map && map->fdf)
			mlx_terminate(map->fdf);
		if (map && map->z_value)
			ft_free_2d_array((void ***)&map->z_value, map->height);
		if (map && map->colors)
			ft_free_2d_array((void ***)&map->colors, map->height);
		if (map)
			ft_free_n_null((void **)&map);
		exit(mlx_errno);
	}
}
