#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char *res;

	res = get_next_line(5);
	printf("res == %s\n", res);
	
	int fd = open("./test/test.txt", O_RDONLY);
	for (size_t i = 0; i < 10; i++)
	{
		res = get_next_line(fd);
		printf("res == %s\n", res);
	}
	close(fd);
	return 0;
}
