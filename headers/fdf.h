/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:51:44 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/07 23:35:43 by JFikents         ###   ########.fr       */
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
#  define CHECK_NULL	-5102
# endif

# ifndef WIDTH
#  define WIDTH	128
# endif

# ifndef HEIGHT
#  define HEIGHT	72
# endif

//_--------------------------------------------------------------------------_//

// ** ------------------------- DATA STRUCTURES -------------------------- ** //

typedef struct s_linked_list_template
{
	void							*content;
	struct s_linked_list_template	*next;
}	t_linked_list_template;

//_--------------------------------------------------------------------------_//

// ** ---------------------------- FUNCTIONS ---------------------------- ** //
mlx_image_t	*mario_bros(mlx_t *window);

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
int			get_r(int rgba);

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
int			get_g(int rgba);

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
int			get_b(int rgba);

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
int			get_a(int rgba);

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
int			get_rgba(int r, int g, int b, int a);

/**
	@note//_DESCRIPTION
	@brief #### Checks for errors and exits the program if an error occurs.
	@brief Checks if `status` is -1, or if `status` is `CHECK_NULL` then checks
	if `check_4_null` is `NULL`. If either is true, then it prints the custom 
	error message or the one from the mlx library to stderr and exits the
	program with the error code.
	@note//_PARAMETERS
	@param status The int to check for -1.
	@param check_4_null The pointer to check for NULL.
	@param error_message The custom error message to print to stderr if needed.
	@param fdf The mlx_t struct to terminate if needed.
	@note//_NOTES
	@note If `status` is different from -1 or `CHECK_NULL` then it does 
	nothing.
	@note If `error_message` is `NULL` then it prints the error message from
	the mlx library.
 */
void		exit_on_error(int status, void *check_4_null, char *error_message,
			mlx_t *fdf);

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
