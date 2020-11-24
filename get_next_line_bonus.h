/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:00:51 by bmayer            #+#    #+#             */
/*   Updated: 2020/11/23 21:19:46 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define FD_LIMIT 256
# include <unistd.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
unsigned int	ft_strlen(const char *str, int line);
void			ft_strlcpy(char *dst, const char *src, unsigned int dstsize);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strrchr(const char *s, int c);

#endif
