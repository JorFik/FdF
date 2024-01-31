/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draws.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:01:10 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/31 21:18:54 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DRAWS_H
# define FDF_DRAWS_H

// ** ---------------------------- LIBRARIES ---------------------------- ** //

# include "fdf.h"

//_--------------------------------------------------------------------------_//

// ** ------------------------- DATA STRUCTURES -------------------------- ** //

/**
	@note//_DESCRIPTION
	@brief #### The map struct.
	@brief The map struct contains the width and height of the map, and the
		map itself with the colors of the map.
	@note//_PARAMETERS
	@param width The width of the map.
	@param height The height of the map.
	@param z_value The Z value of every point in the map as a `int **`.
	@param colors The color of every point in the map as a `int **`.
	@param fdf The `mlx` window, used just in case of an error, to terminate
		the window.
	@param grid The image containing the grid.
	@param drawn_map The image containing the drawn map.
	@param scale The scale of the map.
	@param size[2] The size of the image to fit the map in the scale.
	@param parallel The boolean to determine if the map is in parallel view.
	@note//_NOTES
	@note  `z_value[y][x]` and `colors[y][x]` correspond to the same point.
	@note//_WARNING
	@warning `z_value` and `colors` are allocated, make sure to free them.
 */
typedef struct s_map
{
	uint32_t	width;
	uint32_t	height;
	int			param;
	int			**z_value;
	int			**colors;
	mlx_t		*fdf;
	mlx_image_t	*grid;
	mlx_image_t	*drawn_map;
	int			scale;
	int			size[2];
	int			parallel;
}	t_map;

//_--------------------------------------------------------------------------_//

// ** ---------------------------- FUNCTIONS ---------------------------- ** //

/**
	@note//_DESCRIPTION
	@brief #### Puts a pixel in the given `image`.
	@brief Puts a pixel in the given `image` at the given `x` and `y` 
		coordinates with the given `color`, if the coordinates are inside the
		image.
	@note//_PARAMETERS
	@param image The image to put the pixel in.
	@param x The x coordinate of the pixel.
	@param y The y coordinate of the pixel.
	@param color The color of the pixel.
 */
void		put_pixel(const mlx_image_t *image, int x, int y, int color);

/**
	@note//_DESCRIPTION
	@brief #### Plots the map in parallel view.
	@brief Plots the map in the given `fdf` window in parallel view.
	@note//_PARAMETERS
	@param map The map struct containing all the relevant info to plot the map.
	@note//_NOTES
	@note It creates the image in `map->drawn_map` it will delete it if it
		already exists.
 */
void		plot_map_parallel(t_map *map);

/**
	@note//_DESCRIPTION
	@brief #### Draws the map in Isometric view.
	@brief Plots the map in the given `fdf` window in Isometric view.
	@note//_PARAMETERS
	@param map The map struct containing all the relevant info to plot the map.
	@note//_NOTES
	@note It creates the image in `map->drawn_map` it will delete it if it
		already exists.
 */
void		plot_map(t_map *map);

/**
	@note//_DESCRIPTION
	@brief #### Draws a Grid when used with `draw_ft`.
	@brief Math function that draws a "V" shape, that when used several times
		whith `draw_ft` it draws the grid.
	@note//_PARAMETERS
	@param x The x value of the function used to get the y value on the graph.
	@note//_NOTES
	@note After each call from `draw_ft` the 'V' shape is move diagonally 10
		pixels to the right to print the next line of the grid.
	@note This function is just a debug function, and is not used in the final 
		project.
	@note//_RETURN_VALUE
	@return The y value for the given x value.
 */
float		draw_grid(float x, void *param);

/**
	@note//_DESCRIPTION
	@brief #### Draws a function in range of `x`.
	@brief Plots the given function `ft` in the given `img` from `x[0]` to
		`x[1]` going from `color[0]` to `color[1]`.
	@note//_PARAMETERS
	@param img The image to draw the function on.
	@param ft The function to draw.
	@param x[2] The range of x to draw the function in.
	@param color[2] The colors of the function.
	@note//_NOTES
	@note It will send `map->param` to the function `ft` as the `param` 
		parameter.
	@note It will draw just the coordinates that are inside the image.
	@note This function is just a debug function, and is not used in the final
		project.
 */
void		draw_ft(mlx_image_t *img, float (ft)(float, void *), int x[2],
				t_map *map);

/**
	@note//_DESCRIPTION
	@brief #### Draws a line in the given `image`
	@brief Draws a line from coordinates `xy_1` to coordinates `xy_2` going from
	`color[0]` to `color[1]` on the given `image`.
	@note//_PARAMETERS
	@param image The image to draw the line on.
	@param xy_1 The coordinates of the first point.
	@param xy_2 The coordinates of the second point.
	@param color[2] The colors of the line.
	@note//_NOTES
	@note It will draw just the coordinates that are inside the image.
 */
void		draw_line(const mlx_image_t *image, int xy_1[2], int xy_2[2],
				int color[2]);

//_--------------------------------------------------------------------------_//

#endif