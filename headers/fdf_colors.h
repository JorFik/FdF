/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:57:23 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/31 21:02:27 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_COLORS_H
# define FDF_COLORS_H

// ** ---------------------------- LIBRARIES ---------------------------- ** //

# include "fdf.h"

//_--------------------------------------------------------------------------_//

// ** ---------------------------- FUNCTIONS ---------------------------- ** //

/**
	@note//_DESCRIPTION
	@brief #### Does the change in color.
	@brief Takes the color shift value of each mask multiplies it by the
		`i` value and adds it to the `color` in the appropriate mask.
	@note//_PARAMETERS
	@param c_shift The color shift value of each mask.
	@param i The value to multiply the color shift by.
	@param color The color to change.
	@note//_NOTES
	@note It will not change the color if the `i` value is 0.
	@note//_RETURN_VALUE
	@return The new color.
 */
int			set_color(const double *c_shift, int i, int color);

/**
	@note//_DESCRIPTION
	@brief #### Determines the color shift.
	@brief Determines the color shift needed to go from `c_src` to `c_end`
		in the range from `src` to `end`.
	@note//_PARAMETERS
	@param c_src The color to start from.
	@param c_end The color to end at.
	@param src[2] The coordenate to start from.
	@param end[2] The coordenate to end at.
	@note//_NOTES
	@note Sets the color shift to the middle of the two colors if the range is
		0.
	@note//_RETURN_VALUE
	@return rgba[4] containing the color shift for each mask.
	@note//_WARNING
	@warning The returned value is allocated, make sure to free it.
 */
double		*color_shift(int c_src, int c_end, int src[2], int end[2]);

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

//_--------------------------------------------------------------------------_//

#endif