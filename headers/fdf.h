/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:51:44 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/25 17:03:56 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// ** ---------------------------- LIBRARIES ---------------------------- ** //

# include <math.h> // for sin, cos, tan, sqrt etc.
# include <stdio.h> // for perror
# include <string.h> // for strerror
# include "libft.h"
# include "MLX42.h"

//_--------------------------------------------------------------------------_//

// ** ------------------------------ MACROS ------------------------------ ** //

# ifndef CHECK_NULL
#  define CHECK_NULL -5102
# endif

# ifndef WIDTH
#  define WIDTH 1280
# endif

# ifndef HEIGHT
#  define HEIGHT 720
# endif

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
	@note//_NOTES
	@note  `z_value[y][x]` and `colors[y][x]` correspond to the same point.
	@note//_WARNING
	@warning `z_value` and `colors` are allocated, make sure to free them.
 */
typedef struct s_map
{
	uint32_t	width;
	uint32_t	height;
	void		*param;
	int			**z_value;
	int			**colors;
	mlx_t		*fdf;
	mlx_image_t	*grid;
	mlx_image_t	*drawn_map;
}	t_map;

//_--------------------------------------------------------------------------_//

// ** ---------------------------- FUNCTIONS ---------------------------- ** //
void		put_pixel(mlx_image_t *image, int x, int y, int color);
void		draw_straight(mlx_image_t *image, int *origin, int *final,
				int color[2]);
void		put_line(mlx_image_t *image, int start[2], int end[2],
				int color[2]);
void		plot_map(t_map *map);

/**
	@note//_DESCRIPTION
	@brief ####
	@brief
	@note//_PARAMETERS
	@param
	@note//_NOTES
	@note
	@note//_RETURN_VALUE
	@return
 */

/**
	@note//_DESCRIPTION
	@brief #### Handles the key press to alterate the grid.
	@brief Key hook function that enables the user to toggle the grid, and 
		change inclination of the grid.
	@note//_PARAMETERS
	@param keydata The key data containing the key and the action used by the
		mlx library.
	@param param The `t_map struct` containing all the relevant info to handle
		the grid.
	@note//_NOTES
	@note The grid is enabled by default.
	@note The grid is toggle by pressing the 'P' key.
	@note The grid inclination is increased by pressing the 'Z' key.
	@note The grid inclination is decreased by pressing the 'X' key.
	@note//_RETURN_VALUE
	@return
 */
void		handle_grid(mlx_key_data_t keydata, void *param);

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
	@note//_RETURN_VALUE
	@return The y value for the given x value.
 */
float		draw_grid(float x, void *param);

/**
	@note//_DESCRIPTION
	@brief #### Draws a function in range of `x`.
	@brief Plots the given function `ft` in the given `img` from `x[0]` to
		`x[1]` with the given `color`.
	@note//_PARAMETERS
	@param img The image to draw the function on.
	@param ft The function to draw.
	@param x[2] The range of x to draw the function in.
	@param color[2] The color of the function.
	@note//_NOTES
	@note `color` just uses the first color, to future proof it in case I want
		to add a gradient.
 */
void		draw_ft(mlx_image_t *img, float (ft)(float, void *), int x[2],
				t_map *map);

/**
	@note//_DESCRIPTION
	@brief #### Frees a 2d array.
	@brief Frees the given `array` of size `size`, and sets it to `NULL`.
	@note//_PARAMETERS
	@param array The array to free.
	@param size The size of the array.
	@note//_NOTES
	@note If `size` is -1 then it frees the array until it finds a `NULL`.
	@note The `array` is a triple pointer, so it can be set to `NULL`.
	@note It uses `ft_free_n_null` to free the array.
		See `libft/h_files/libft_mem_allocation.h` for more information.
	@see ft_free_n_null
 */
void		ft_free_2d_array(void ***array, int size);

/**
	@note//_DESCRIPTION
	@brief #### Reads the map file.
	@brief Reads `filename` and formats it into the given struct `map` saving
		all the relevant values to it.
	@note//_PARAMETERS
	@param map The struct to read the map into.
	@param filename The file containing the map to read.
 */
void		read_map(char *filename, t_map *map);

/**
	@note//_DESCRIPTION
	@brief #### Draws x, y, and z axis.
	@brief Draws the x, y, and z axis on the given `fdf` window.
	@note//_PARAMETERS
	@param map The map struct containing the `fdf` window.
	@note//_NOTES
	@note Function is just reference for the maps.
	@note//_RETURN_VALUE
	@return The image of the axis.
 */
mlx_image_t	*draw_axis(t_map *map);

/**
	@note//_DESCRIPTION
	@brief #### Checks if the (x, y) is valid.
	@brief Checks if the given `xy` coordinates are inside the given `image`.
	@note//_PARAMETERS
	@param xy The coordinates to check.
	@param image The image to check the coordinates in.
	@note//_RETURN_VALUE
	@return `0` if the coordinates are outside of the image, `1` if they are
		inside.
 */
int			is_coord_valid(int *xy, mlx_image_t *image);

/**
	@note//_DESCRIPTION
	@brief #### Draws a line in the given `image`
	@brief Draws a line from coordinates `xy_1` to coordinates `xy_2` with the 
		given `color` on the given `image`.
	@note//_PARAMETERS
	@param image The image to draw the line on.
	@param xy_1 The coordinates of the first point.
	@param xy_2 The coordinates of the second point.
	@param color The color of the line.
	@note//_NOTES
	@note If any of the coordinates are outside of the image, then it does 
		nothing.
 */
void		draw_line(mlx_image_t *image, int xy_1[2], int xy_2[2],
			int color[2]);

/**
	@note//_DESCRIPTION
	@brief #### Decodes from `rgba` the red value.
	@brief Takes the `rgba` value and takes the `red` value from it.
	@note//_PARAMETERS
	@param rgba The rgba value.
	@note//_RETURN_VALUE
	@return The red value.
 */
int			get_r(int rgba);

/**
	@note//_DESCRIPTION
	@brief #### Decodes from `rgba` the green value.
	@brief Takes the `rgba` value and takes the `green` value from it.
	@note//_PARAMETERS
	@param rgba The rgba value.
	@note//_RETURN_VALUE
	@return The green value.
 */
int			get_g(int rgba);

/**
	@note//_DESCRIPTION
	@brief #### Decodes from `rgba` the blue value.
	@brief Takes the `rgba` value and takes the `blue` value from it.
	@note//_PARAMETERS
	@param rgba The rgba value.
	@note//_RETURN_VALUE
	@return The blue value.
 */
int			get_b(int rgba);

/**
	@note//_DESCRIPTION
	@brief #### Decodes from `rgba` the alpha value.
	@brief Takes the `rgba` value and takes the `alpha` value from it.
	@note//_PARAMETERS
	@param rgba The rgba value.
	@note//_RETURN_VALUE
	@return The alpha value.
 */
int			get_a(int rgba);

/**
	@note//_DESCRIPTION
	@brief #### Returns the rgba value of the given r, g, b, and a values.
	@brief Encodes the r, g, b, and a values into a single int.
	@note//_PARAMETERS
	@param r The red value.
	@param g The green value.
	@param b The blue value.
	@param a The alpha value.
	@note//_RETURN_VALUE
	@return Encoded rgba value.
 */
int			get_rgba(int r, int g, int b, int a);

/**
	@note//_DESCRIPTION
	@brief #### Checks for errors and exits the program if an error occurs.
	@brief Checks if `status` is -1, or if `status` is `CHECK_NULL` then checks
	if `check_4_null` is `NULL`. If either is true, then it prints the custom 
	error message or the one from the mlx library to stderr and exits the
	program with the error code.
	@note//_PARAMETERS
	@param status The int to check for -1 or `CHECK_NULL`.
	@param check_4_null The pointer to check for `NULL` if `status` is set to
		`CHECK_NULL`.
	@param error_message The custom error message to print to stderr if needed.
	@param fdf The `mlx_t struct` to terminate if needed.
	@note//_NOTES
	@note If `status` is different from -1 or `CHECK_NULL` then it does 
	nothing.
	@note If `error_message` is `NULL` then it prints the error message from
	the mlx library.
 */
void		exit_on_error(int status, void *check_4_null, char *error_message,
				t_map *map);

//_--------------------------------------------------------------------------_//

#endif
/*
// ?? ------------------------ ALLOWED FUNCTIONS ------------------------ ?? //

?	open(char *file path, int flags, (OPT) permissions)
		Opens a file and returns a file descriptor.
?	close(int file descriptor)
		Closes a file descriptor.
?	read(int file descriptor, void *buffer, int number of bytes)
		Reads a file descriptor n bytes, and stores it in the buffer.
?	write(int file descriptor, void *buffer, int number of bytes)
		Writes a file descriptor n bytes from the buffer.
?	malloc(int number of bytes)
		Allocates n bytes of memory and returns a pointer to it.
?	free(void *pointer)
		Frees the memory allocated by malloc.
?	perror(char *msg)
		Prints the error message to stderr.
?	strerror(int error number)
		Returns the error message as a string.
?	exit(int status)
		Exits the program with the given status.
? All functions of the math
? All functions of the MiniLibX

//_--------------------------------------------------------------------------_//
*/
