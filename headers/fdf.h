/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:51:44 by JFikents          #+#    #+#             */
/*   Updated: 2023/12/18 23:01:31 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// ** ---------------------------- LIBRARIES ---------------------------- ** //

# include "libft.h"
# include <math.h> // for sin, cos, tan, sqrt etc.
# include <stdio.h> // for perror
# include <string.h> // for strerror

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


//_--------------------------------------------------------------------------_//
*/
