/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:27:34 by JFikents          #+#    #+#             */
/*   Updated: 2024/01/06 20:13:32 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_on_error(int status, void *check_4_null, char *error_message,
			mlx_t *fdf)
{
	if (status == -1 || (status == CHECK_NULL && !check_4_null))
	{
		if (error_message)
			perror(error_message);
		else
			perror(mlx_strerror(mlx_errno));
		if (fdf)
			mlx_terminate(fdf);
		exit(mlx_errno);
	}
}
