#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
//mandatory
int main()
{
	char *res;

	res = get_next_line(1025);
	printf("invalid_fd == %s\n", res);
	if(res)
		free(res);
	int fd = open("./test/test.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("null_file == %s\n", res);
	if(res)
		free(res);
	int fd2 = open("./test/test2.txt", O_RDONLY);
	res = "";
	while (res != NULL)
	{
		res = get_next_line(fd2);
		printf("basic_test == %s\n", res);
		if(res)
			free(res);
	}
	int fd3 = open("./test/test3.txt", O_RDONLY);
	res = "";
	while (res != NULL)
	{
		res = get_next_line(fd3);
		printf("only_line_char_test == %s\n", res);
		if(res)
			free(res);
	}
	int fd4 = open("./get_next_line.h", O_RDONLY);
	for (size_t i = 0; i < 5; i++)
	{
		res = get_next_line(fd4);
		printf("close_test == %s\n", res);
		if(res)
			free(res);
		if(i == 0)
			close(fd4);
	}
	close(fd);
	close(fd2);
	close(fd3);
	system("leaks a.out");
	return 0;
}
