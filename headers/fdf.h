/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:51:44 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/04 00:40:48 by JFikents         ###   ########.fr       */
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

# ifndef TEMPLATE_MACRO
#  define TEMPLATE_MACRO	42
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

/**
	@note//_DESCRIPTION
	@brief ####
	@brief
	@note//_PARAMETERS
	@param
	@note//_RETURN
	@return
	@note//_NOTES
	@note
	@note//_SEE_ALSO
	@see
	@note//_WARNINGS
	@warning
 */
void	ft_place_holder(void);

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
