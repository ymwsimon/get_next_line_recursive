/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:16:09 by mayeung           #+#    #+#             */
/*   Updated: 2023/11/11 23:26:12 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_readbuff(char **remain, char **readbuf, ssize_t *readsize, int fd)
{
	if (readbuf)
		*readbuf = 0;
	if (!(*remain))
	{
		*readbuf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (*readbuf && fd >= 0)
		{
			*readsize = read(fd, *readbuf, BUFFER_SIZE);
			if (*readsize > 0)
				(*readbuf)[*readsize] = 0;
		}
		else
			*readsize = -1;
	}
	else
	{
		*readbuf = *remain;
		*readsize = ft_strlen(*readbuf);
		*remain = 0;
	}
}

char	*ft_foundnewline(ssize_t rs, ssize_t i, char *readbuf, char **remain)
{
	char	*temp;

	if (rs - i - 1)
		*remain = ft_strdup(&readbuf[i + 1]);
	temp = malloc(i + 2);
	if (temp)
		ft_strncpy(temp, readbuf, i + 2);
	free(readbuf);
	return (temp);
}

char	*ft_keepread(int fd, char *readbuf)
{
	char	*temp;
	char	*line;

	temp = get_next_line(fd);
	line = ft_strjoin(readbuf, temp);
	free(temp);
	free(readbuf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remain[4096] = {0};
	ssize_t		i;
	ssize_t		readsize;
	char		*readbuf;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 4095)
		return (0);
	ft_readbuff(&remain[fd], &readbuf, &readsize, fd);
	if (readsize > 0)
	{
		i = 0;
		while (i < readsize && readbuf[i] != '\n')
			i++;
		if (i < readsize)
			return (ft_foundnewline(readsize, i, readbuf, &remain[fd]));
		else
			return (ft_keepread(fd, readbuf));
	}
	else
	{
		free(readbuf);
		return (0);
	}
}
