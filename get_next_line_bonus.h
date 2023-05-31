#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*ft_strdup(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size);

void	ft_strncpy(char *dst, const char *src, size_t size);

#endif
