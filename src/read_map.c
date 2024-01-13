/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:19:56 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/13 12:43:49 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//_ 1,0x810202
int	get_color(char *str)
{
	int			i;
	int			j;
	int			color;
	const int	jump_comma_and_0x = 3;

	i = 0;
	j = 0;
	color = 0;
	if (!ft_strchr(str, ','))
		return (0);
	str = ft_strchr(str, ',') + jump_comma_and_0x;
	while (str && str[i])
	{
		str[i] = ft_toupper(str[i]);
		j = 0;
		while (j < 17 && "0123456789ABCDEF"[j] != str[i])
			j++;
		color *= 16;
		if (j < 17 && str[i] == "0123456789ABCDEF"[j])
			color += j;
		i++;
	}
	return (color);
}

void	measure_map(t_map	*map, char *filename)
{
	int		fd;
	char	*line;
	char	**split;
	int		check_width;

	fd = open(filename, O_RDONLY);
	exit_on_error(fd, NULL, "Error Opening File for measures", map);
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		check_width = 0;
		while (split[check_width])
			check_width++;
		free_2d_array((void ***)&split, -1);
		if (map->width && check_width != map->width)
			exit_on_error(-1, NULL, "Invalid Map", map);
		map->width = check_width;
		ft_free_n_null((void **)&line);
		line = get_next_line(fd);
		map->height++;
	}
	ft_close(&fd);
}

void	allocate_mem_for_map(t_map *map)
{
	int	i;

	i = 0;
	map->z_value = ft_calloc(map->height, sizeof(int *));
	exit_on_error(CHECK_NULL, map->z_value, "Error Allocating Memory", map);
	map->colors = ft_calloc(map->height, sizeof(int *));
	exit_on_error(CHECK_NULL, map->colors, "Error Allocating Memory", map);
	while (i < map->height)
	{
		map->z_value[i] = ft_calloc(map->width, sizeof(int));
		exit_on_error(CHECK_NULL, map->z_value[i], "Error Allocating Memory",
			map);
		map->colors[i] = ft_calloc(map->width, sizeof(int));
		exit_on_error(CHECK_NULL, map->colors[i], "Error Allocating Memory",
			map);
		i++;
	}
}

void	read_map(char *file, t_map *map)
{
	int		fd;
	int		x;
	int		y;
	char	*line;
	char	**split;

	y = -1;
	measure_map(map, file);
	allocate_mem_for_map(map);
	exit_on_error(fd = open(file, O_RDONLY), NULL, "Error Opening File", map);
	line = get_next_line(fd);
	while (line && ++y < map->height)
	{
		split = ft_split(line, ' ');
		x = -1;
		while (split && split[++x])
		{
			map->z_value[y][x] = ft_atoi(split[x]);
			map->colors[y][x] = get_color(split[x]);
		}
		free_2d_array((void ***)&split, -1);
		ft_free_n_null((void **)&line);
		line = get_next_line(fd);
	}
	exit_on_error(ft_close(&fd), NULL, "Error Closing File", map);
}

	// if (ft_strchr(split[0], ','))
	// 	map.colors = ft_split(split[0], ',');

// void	check_int(char *argv, t_stacks *stack)
// {
// 	if (*argv == '+')
// 		argv++;
// 	if (ft_strlen(argv) > 10)
// 	{
// 		if (ft_strncmp(argv, "-2147483648", 12) > 0 && argv[0] == '-')
// 			exit(del_lists(stack, 1));
// 	}
// 	else if (ft_strlen(argv) > 9)
// 	{
// 		if (ft_strncmp(argv, "2147483647", 11) > 0)
// 			exit(del_lists(stack, 1));
// 	}
// }