#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int arc, char **arv)
{
	char *line;
	int	fd;

	line = 0;
	if (arc == 2 || arc == 3)
	{
		if (arc == 2)
			fd = open(arv[1], O_RDONLY);
		else
			fd = atoi(arv[2]);
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (0);
}
