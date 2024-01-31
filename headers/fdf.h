/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:51:44 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/31 21:18:49 by JFikents         ###   ########.fr       */
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
# include "fdf_colors.h" // for the color related functions
# include "fdf_draws.h" // for the draw related functions

//_--------------------------------------------------------------------------_//

// ** ------------------------- MACROS AND ENUMS ------------------------- ** //

# ifndef CHECK_NULL
#  define CHECK_NULL -5102
# endif

# ifndef WIDTH
#  define WIDTH 3200
# endif

# ifndef HEIGHT
#  define HEIGHT 1600
# endif

enum
{
	R,
	G,
	B,
	A
};

enum
{
	H,
	W
};

//_--------------------------------------------------------------------------_//

// ** ---------------------------- FUNCTIONS ---------------------------- ** //

/**
	@note//_DESCRIPTION
	@brief #### Initializes the map struct.
	@brief Initializes the map struct and initializes the `mlx` window.
	@note//_NOTES
	@note It sets the `param` to 2, the `scale` to 2, the `size[H]` to `HEIGHT`,
		and the `size[W]` to `WIDTH`, the rest of the values are set to 0 or
		`NULL`.
	@note `map->fdf` is set to the `mlx_t struct` returned by `mlx_init`.
	@note//_RETURN_VALUE
	@return The initialized map struct.
	@note//_WARNING
	@warning The returned value is allocated, make sure to free it.
 */
t_map		*map_initializer(void);

/**
	@note//_DESCRIPTION
	@brief #### Loop hook function to exit.
	@brief Loop hook function that enables the user to exit the program by
		pressing the `ESC` key.
	@note//_PARAMETERS
	@param param The `mlx_t struct` containing the `fdf` window.
	@note//_NOTES
	@note `ESC` to exit the program.
 */
void		key_press(void *param);

/**
	@note//_DESCRIPTION
	@brief #### Prints the map data.
	@brief Prints the data from `map->z_value` and `map->colors` to stdout.
	@note//_PARAMETERS
	@param map The map struct containing the data to print.
	@note//_NOTES
	@note This function is just a debug function, and is not used in the final
		project.
 */
void		print_map(t_map *map);

/**
	@note//_DESCRIPTION
	@brief #### Handles the key presses.
	@brief Key hook function that enables the user to zoom in and out, move the
		map, change to parallel view, refresh the map, and rotate the map.
	@note//_PARAMETERS
	@param keydata The key data containing the key and the action used by the
		mlx library.
	@param param The `t_map struct` containing all the relevant info to handle
		the input.
	@note//_NOTES
	@note `R` to reset the map.
	@note `P` to change between parallel and isometric view.
	@note `W` to move up.
	@note `S` to move down.
	@note `A` to move left.
	@note `D` to move right.
	@note `UP` to zoom in.
	@note `DOWN` to zoom out.
	@note `LEFT` to rotate backwards.
	@note `RIGHT` to rotate forwards.
 */
void		handle_grid(mlx_key_data_t keydata, void *param);

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
	@brief #### Checks if the (x, y) is valid.
	@brief Checks if the given `xy` coordinates are inside the given `image`.
	@note//_PARAMETERS
	@param xy The coordinates to check.
	@param image The image to check the coordinates in.
	@note//_RETURN_VALUE
	@return `0` if the coordinates are outside of the image, `1` if they are
		inside.
 */
int			is_coord_valid(int *xy, const mlx_image_t *image);

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
