/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:49:11 by bmayer            #+#    #+#             */
/*   Updated: 2020/11/23 21:00:35 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		free_ret(char **freestr, int retcode)
{
	if (freestr)
	{
		*freestr = 0;
		free(*freestr);
	}
	return (retcode);
}

int		save_line(char **line, char **fd_read, int nb_read)
{
	char	*temp;
	int		len;

	if (!*fd_read)
		return (free_ret(0, -1));
	if (nb_read < 0)
		return (free_ret(&*fd_read, -1));
	len = ft_strlen(*fd_read, 1);
	if (!(*line = malloc(sizeof(char) * (len + 1))))
		return (free_ret(&*fd_read, -1));
	if (!**fd_read)
		*fd_read = "";
	ft_strlcpy(*line, *fd_read, len + 1);
	if ((*fd_read)[len])
	{
		temp = *fd_read;
		*fd_read = ft_strdup(*fd_read + len + 1);
		free(temp);
		if (!fd_read)
			return (free_ret(0, -1));
	}
	else
		return (free_ret(&*fd_read, 0));
	return (free_ret(0, 1));
}

char	*add_buffer(char *fd_read, char *buffer)
{
	char		*result;

	result = ft_strjoin(fd_read, buffer);
	free(fd_read);
	return (result);
}

int		get_next_line(int fd, char **line)
{
	static char	*fd_read[FD_LIMIT];
	int			nb_read;
	char		*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || !buffer || read(fd, buffer, 0) < 0)
		return (-1);
	while (1)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			break ;
		buffer[nb_read] = 0;
		if (!fd_read[fd])
			fd_read[fd] = ft_strdup(buffer);
		else
			fd_read[fd] = add_buffer(fd_read[fd], buffer);
		if (!fd_read[fd] || ft_strrchr(buffer, '\n') || nb_read == 0)
			break ;
	}
	free(buffer);
	buffer = 0;
	return (save_line(line, fd_read + fd, nb_read));
}
