#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	times;
	void *res;

	malloc(BUFFER_SIZE);
	/*
	・改行まで1文字づつ読み込む
	・1回につき1行読み込む
	・BUFFER_SIZEが尽きるまで読み取る
	*/
	
	read(fd, res, 1);
	return(res);
}