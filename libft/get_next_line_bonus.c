/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:05:50 by JFikents          #+#    #+#             */
/*   Updated: 2023/11/15 21:51:15 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_addfront(char *pre, char *mid, char *pos)
{
	int		i;
	int		n_i;
	char	*new;

	i = 0;
	n_i = 0;
	new = ft_calloc(ft_strlen(pos)
			+ ft_strlen(pre) + ft_strlen(mid) + 1, sizeof(char));
	if (!new)
		return ((void *)ft_back2zero(&pos, NULL));
	while (pre[i])
		new[n_i++] = pre[i++];
	i = 0;
	while (mid && mid[i])
		new[n_i++] = mid[i++];
	i = 0;
	while (pos && pos[i])
		new[n_i++] = pos[i++];
	ft_back2zero(&pos, NULL);
	return (new);
}

static void	ft_erease_front(int lr_i, char *last_read)
{
	int		i;
	char	buffer[BUFFER_SIZE + 1];

	i = 0;
	while (i <= BUFFER_SIZE)
		buffer[i++] = 0;
	i = 0;
	while (last_read[lr_i])
		buffer[i ++] = last_read[lr_i ++];
	i = 0;
	while (i <= BUFFER_SIZE)
		last_read[i++] = 0;
	i = 0;
	lr_i = 0;
	while (buffer[i])
		last_read[lr_i ++] = buffer[i ++];
}

static char	*ft_check_last_read(char *last_read, char *line)
{
	char	*new_line;
	int		i;
	int		lr_i;

	i = 0;
	lr_i = 0;
	new_line = ft_strchr(last_read, '\n');
	if (!new_line)
	{
		while (last_read[lr_i])
			line[i ++] = last_read[lr_i ++];
		ft_erease_front(lr_i, last_read);
		return (line);
	}
	line = ft_calloc(new_line - last_read + 2, sizeof(char));
	if (!line)
		return ((void *) 0);
	while (last_read[lr_i] != '\n')
		line[i ++] = last_read[lr_i ++];
	line[i] = last_read[lr_i ++];
	ft_erease_front(lr_i, last_read);
	return (line);
}

void	ft_init_lines(char *pre, char *tmp)
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		pre[i] = 0;
		tmp[i] = 0;
		i ++;
	}
}

char	*get_next_line(int fd)
{
	static char	last_read[MAX_FD][BUFFER_SIZE + 1];
	t_lines		line;
	int			check_read;
	int			fd_i;

	ft_init_lines(line.pre, line.tmp);
	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (NULL);
	fd_i = fd;
	line.line = ft_check_last_read(last_read[fd_i], line.pre);
	if (line.line != line.pre)
		return (line.line);
	check_read = read(fd, line.tmp, BUFFER_SIZE);
	line.line = ft_handle_nl(line.tmp, last_read[fd_i], check_read);
	if ((check_read < 1 && !*line.pre) || check_read == -1)
		return ((void *)ft_back2zero((char **) &line.line, last_read[fd_i]));
	else if (line.line || !check_read)
		line.line = ft_addfront(line.pre, NULL, line.line);
	else
		line.line = ft_addfront(line.pre, line.tmp, get_next_line(fd));
	return (line.line);
}
