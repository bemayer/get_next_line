/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:00:51 by bmayer            #+#    #+#             */
/*   Updated: 2020/11/24 20:30:15 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_FD 256

int				get_next_line(int fd, char **line);
unsigned int	ft_strlen(const char *str, int line);
void			ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
char			*ft_strdup(const char *src, unsigned int len);
char			*ft_strjoin(char const *s1, char const *s2);
int				find_lr(const char *s);

#endif
