/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:51:44 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/13 13:41:51 by JFikents         ###   ########.fr       */
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
	@note//_NOTES
	@note  `z_value[y][x]` and `colors[y][x]` correspond to the same point.
	@note//_WARNING
	@warning `z_value` and `colors` are allocated, make sure to free them.
 */
typedef struct s_map
{
	int		width;
	int		height;
	int		**z_value;
	int		**colors;
	mlx_t	*fdf;
}	t_map;

//_--------------------------------------------------------------------------_//

// ** ---------------------------- FUNCTIONS ---------------------------- ** //

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
	@brief ####
	@brief
	@note//_PARAMETERS
	@param
	@note//_NOTES
	@note
	@note//_RETURN_VALUE
	@return
 */
void		free_2d_array(void ***array, int size);

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
void		read_map(char *filename, t_map *map);

/**
	@note//_DESCRIPTION
	@brief #### Draws the given Function.
	@brief Draws the given `function` on the `image` from the coordinates
		`xy[0]` to `xy[1]` with the given `color`. 
	@note//_PARAMETERS
	@param image The image to draw the function on.
	@param function The function to draw.
	@param xy The coordinates to draw the function from and to.
	@param color The color of the function.
	@note//_NOTES
	@note The function must be a function that takes a float and returns a float
	@note The coordinates must be in the format of `{{x1, y1}, {x2, y2}}`
	@note The coordinates must be inside the image and the final coordinates
		must be greater than the initial coordinates.
	@note The final coordinates must be a point inside the given function, else
		it won't draw the function.
 */
void		draw_with_function(mlx_image_t *image, float (function)(float),
				int xy[2][2], int color);

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
void		draw_line(mlx_image_t *image, int xy_1[2], int xy_2[2], int color);

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
