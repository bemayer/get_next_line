/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:49:11 by bmayer            #+#    #+#             */
/*   Updated: 2020/11/25 12:26:53 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *save_line(char **fd_read, char *buffer)
{
	int		len;
	char	*temp;
	char	*line;

	len = ft_strlen(*fd_read, 1);
	line = ft_strdup(*fd_read, len);
	temp = *fd_read;
	*fd_read = ft_strdup(*fd_read + len + 1, ft_strlen(*fd_read + len + 1, 0));
	free(temp);
	free(buffer);
	return line;
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

char *get_next_line(int fd)
{
	static char	*fd_read[MAX_FD];
	int			nb_read;
	char		*buffer;

	// Vérifications de base
	if (BUFFER_SIZE <= 0 || fd < 0 || !(buffer = malloc(sizeof(char)
		* (BUFFER_SIZE + 1))) || read(fd, buffer, 0) < 0)
		return (-1);

	// Si j'ai déjà sauvé des trucs et qu'il y a un retour à la ligne dedans, alors j'ai déjà ma ligne, je la retourne sans rien lire
	if (((fd_read[fd]) && find_lr(fd_read[fd])))
		// Je retourne un pointeur sur la ligne (une string jusqu'au retour à la ligne) et je sauvegarde le reste
		return (save_line(fd_read + fd, buffer));

	// Je lis jusqu'à ce que je n'ai plus rien à lire, jusqu'à la fin du fichier
	while ((nb_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		// J'ajoute ce que je viens de lire à ce que j'ai déjà sauvé
		add_buffer(fd_read + fd, buffer, nb_read);

		// Si je trouve un retour à la ligne, je m'arrête là.
		if (find_lr(fd_read[fd]))
			// Je retourne un pointeur sur la ligne (une string jusqu'au retour à la ligne) et je sauvegarde le reste
			return (save_line(fd_read + fd, buffer));
	}

	// Si j'atteints la fin du fichier, je retourne ce qu'il reste
	if (fd_read[fd])
	{
		// Si j'ai déjà lu quelque chose, je retourne ce que j'ai sauvegardé
		*line = ft_strdup(fd_read[fd], ft_strlen(fd_read[fd], 0));
		free(fd_read[fd]);
		fd_read[fd] = 0;
	}
	else
		// Sinon, je retourne une ligne vide
		*line = ft_strdup("", 1);
	free(buffer);
	return line;
}
