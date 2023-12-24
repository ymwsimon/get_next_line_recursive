/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayeung <mayeung@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:16:35 by mayeung           #+#    #+#             */
/*   Updated: 2023/12/24 14:48:33 by mayeung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*t;

	i = 0;
	while (s && s[i])
		i++;
	t = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (t && s && s[i])
	{
		t[i] = s[i];
		i++;
	}
	if (t)
		t[i] = '\0';
	return (t);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	while (s1 && s1[i])
		i++;
	j = 0;
	while (s2 && s2[j])
		j++;
	res = malloc(sizeof(char) * (i + j + 1));
	if (res)
	{
		i = 0;
		while (s1 && *s1)
			res[i++] = *s1++;
		j = 0;
		while (s2 && *s2)
			res[i + j++] = *s2++;
		res[i + j] = '\0';
	}
	return (res);
}
