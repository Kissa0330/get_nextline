#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	char *res;

	res = get_next_line(5);
	printf("test_null == %s\n", res);
	
	int fd = open("./test/test.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("test1 == %s\n", res);
	res = "";
	int fd2 = open("./test/test2.txt", O_RDONLY);
	while (res != NULL)
	{
		res = get_next_line(fd2);
		printf("test2 == %s\n", res);
	}
	res = "";
	int fd3 = open("./test/test3.txt", O_RDONLY);
	while (res != NULL)
	{
		res = get_next_line(fd3);
		printf("test3 == %s\n", res);
	}
	close(fd);
	close(fd2);
	close(fd3);
	return 0;
}
