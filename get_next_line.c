/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:16:11 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/24 16:23:21 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_readbuff(char **remain, char **readbuf, int *readsize, int fd)
{
	if (*remain)
	{
		*readbuf = *remain;
		*readsize = 0;
		while ((*readbuf)[*readsize])
				(*readsize)++;
		*remain = NULL;
	}
	else
	{
		*readbuf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (*readbuf)
		{
			*readsize = read(fd, *readbuf, BUFFER_SIZE);
			if (*readsize > 0)
				(*readbuf)[*readsize] = '\0';
		}
		else
			*readsize = -1;
	}
}

char	*ft_foundnewline(int i, char *readbuf, char **remain)
{
	char	*res;
	int		j;

	if (readbuf[i + 1])
		*remain = ft_strdup(&readbuf[i + 1]);
	res = malloc(sizeof(char) * (i + 2));
	j = 0;
	while (res && j <= i)
	{	
		res[j] = readbuf[j];
		j++;
	}
	if (res)
		res[j] = '\0';
	free(readbuf);
	return (res);
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
	static char	*remain = NULL;
	int			i;
	int			readsize;
	char		*readbuf;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ft_readbuff(&remain, &readbuf, &readsize, fd);
	if (readsize > 0)
	{
		i = 0;
		while (i < readsize && readbuf[i] != '\n')
			i++;
		if (i < readsize)
			return (ft_foundnewline(i, readbuf, &remain));
		else
			return (ft_keepread(fd, readbuf));
	}
	else
	{
		free(readbuf);
		return (NULL);
	}
}
