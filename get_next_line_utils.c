/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmayer <mayer.benoit@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 20:55:20 by bmayer            #+#    #+#             */
/*   Updated: 2020/11/24 17:57:11 by bmayer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// ft_strlen special: si line vaut 1, renvoie le nombre de char jusqu'à la fin de la string ou jusqu'à un retour à la ligne,
//                    sinon, renvoie le nombre de char jusqu'à la fin de la string
unsigned int	ft_strlen(const char *str, int line)
{
	unsigned int i;

	i = 0;
	while (str[i] && (line || str[i] != '\n'))
		i++;
	return i;
}

void			ft_strlcpy(char *dst, const char *src, unsigned int dstsize)
{
	unsigned int i;

	i = 0;
	while ((src[i]) && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char			*ft_strdup(const char *src, unsigned int len)
{
	char			*dest;

	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strlcpy(dest, src, len + 1);
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!(ptr = malloc(sizeof(char) * (ft_strlen(s1, 0) +
			ft_strlen(s2, 0) + 1))))
		return (0);
	while (*s1)
		ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = 0;
	return (ptr);
}

int				find_lr(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
