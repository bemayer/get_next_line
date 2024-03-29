/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:49:11 by bmayer            #+#    #+#             */
/*   Updated: 2020/11/25 12:28:10 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		save_line(char **line, char **fd_read, char *buffer)
{
	int		len;
	char	*temp;

	len = ft_strlen(*fd_read, 1);
	*line = ft_strdup(*fd_read, len);
	temp = *fd_read;
	*fd_read = ft_strdup(*fd_read + len + 1, ft_strlen(*fd_read + len + 1, 0));
	free(temp);
	free(buffer);
	return (1);
}

void	add_buffer(char **fd_read, char *buffer, unsigned int nb_read)
{
	char		*temp;

	buffer[nb_read] = 0;
	if (*fd_read)
	{
		temp = *fd_read;
		*fd_read = ft_strjoin(*fd_read, buffer);
		free(temp);
		temp = 0;
	}
	else
		*fd_read = ft_strdup(buffer, nb_read);
}

int		get_next_line(int fd, char **line)
{
	static char	*fd_read[MAX_FD];
	int			nb_read;
	char		*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line || !(buffer = malloc(sizeof(char)
		* (BUFFER_SIZE + 1))) || read(fd, buffer, 0) < 0)
		return (-1);
	if (((fd_read[fd]) && find_lr(fd_read[fd])))
		return (save_line(line, fd_read + fd, buffer));
	while ((nb_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		add_buffer(fd_read + fd, buffer, nb_read);
		if (find_lr(fd_read[fd]))
			return (save_line(line, fd_read + fd, buffer));
	}
	if (fd_read[fd])
	{
		*line = ft_strdup(fd_read[fd], ft_strlen(fd_read[fd], 0));
		free(fd_read[fd]);
		fd_read[fd] = 0;
	}
	else
		*line = ft_strdup("", 1);
	free(buffer);
	return (nb_read == 0 ? 0 : -1);
}
