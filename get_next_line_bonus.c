/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:16:09 by mayeung           #+#    #+#             */
/*   Updated: 2023/07/30 19:16:10 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_readbuff(char **remain, char **rb, ssize_t *rs, int fd)
{
	if (rb)
		*rb = 0;
	if (!(*remain))
	{
		*rb = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (*rb && fd != 2 && fd >= 0)
		{
			*rs = read(fd, *rb, BUFFER_SIZE);
			if (*rs > 0)
				(*rb)[*rs] = 0;
		}
		else
			*rs = -1;
	}
	else
	{
		*rb = *remain;
		*rs = ft_strlen(*rb);
		*remain = 0;
	}
}

char	*ft_foundnewline(int rs, ssize_t i, char *rb, char **remain)
{
	char	*temp;

	if (rs - i - 1)
		*remain = ft_strdup(&rb[i + 1]);
	temp = malloc(i + 2);
	if (temp)
		ft_strncpy(temp, rb, i + 2);
	free(rb);
	return (temp);
}

char	*ft_keepread(int fd, char *rb)
{
	char	*temp;
	char	*line;

	temp = get_next_line(fd);
	line = ft_strjoin(rb, temp);
	free(temp);
	free(rb);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remain[4096] = {0};
	ssize_t		i;
	ssize_t		rs;
	char		*rb;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 4095)
		return (0);
	ft_readbuff(&remain[fd], &rb, &rs, fd);
	if (rs > 0)
	{
		i = 0;
		while (i < rs && rb[i] != '\n')
			i++;
		if (i < rs)
			return (ft_foundnewline(rs, i, rb, &remain[fd]));
		else
			return (ft_keepread(fd, rb));
	}
	else
	{
		free(rb);
		return (0);
	}
}
