#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*t;

	i = 0;
	t = 0;
	if (s)
	{
		while (s[i])
			i++;
		t = malloc(i + 1);
		if (t)
		{
			i = 0;
			while (s[i])
			{
				t[i] = s[i];
				i++;
			}
			t[i] = 0;
		}
	}
	return (t);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	res = 0;
	if (!s1 && s2)
		res = ft_strdup(s2);
	if (s1 && !s2)
		res = ft_strdup(s1);
	if (s1 && s2)
	{
		res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (res)
		{
			res[0] = 0;
			ft_strlcat(res, s1, ft_strlen(s1) + 1);
			ft_strlcat(res, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
		}
	}
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size && dst[i])
		i++;
	j = 0;
	while (size && (i + j) < (size - 1) && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	if ((i + j) < size)
		dst[i + j] = 0;
	while (src[j])
		j++;
	return (i + j);
}

void	ft_strncpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dst && src)
	{
		while (i < size - 1 && size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		if (size)
			dst[i] = 0;
	}
}
