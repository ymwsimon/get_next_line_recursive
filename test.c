#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main(int arc, char **arv)
{
	char *line;
	int	fd1;
	int fd2;
	int fd3;

	line = 0;
	if (arc == 2 && arv[1][0] == 'b')
	{
		fd1 = open("aaaa", O_RDONLY);
		fd2 = open("bbbb", O_RDONLY);
		fd3 = open("cccc", O_RDONLY);

		line = get_next_line(fd1);
		printf("%s", line);
		line = get_next_line(fd2);
		printf("%s", line);


		line = get_next_line(fd1);
		printf("%s", line);
		line = get_next_line(fd2);
		printf("%s", line);
		line = get_next_line(fd3);
		printf("%s", line);

		line = get_next_line(fd1);
		printf("%s", line);
		line = get_next_line(fd2);
		printf("%s", line);
		
		close(fd1);
		close(fd2);
		close(fd3);
	}
	else
	{
		fd1 = open("aaaa", O_RDONLY);

		line = get_next_line(fd1);
		printf("%s", line);
		line = get_next_line(fd1);
		printf("%s", line);
		line = get_next_line(fd1);
		printf("%s", line);

		close(fd1);
	}
	/*if (arc == 2 || arc == 3)
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
	}*/
	return (0);
}
