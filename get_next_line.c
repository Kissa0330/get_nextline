/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:48:07 by rtakano           #+#    #+#             */
/*   Updated: 2022/07/01 00:42:03 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*read_file(int fd, int *read_res)
{
	char	*res;

	if (!*read_res)
		return (NULL);
	res = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[BUFFER_SIZE] = '\0';
	*read_res = read(fd, res, BUFFER_SIZE);
	if (*read_res == -1)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static int	read_res = 1;
	static int	current_fd = 0;
	char		*res;
	char		*buf;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (current_fd != fd)
	{
		current_fd = fd;
		read_res = 1;
	}
	if (!read_res)
		return (NULL);
	for (size_t i = 0; i < 10; i++)
	// while (!ft_strchr(res, '\n') && read_res)
	{
		printf("read_res == %d\n", read_res);
		buf = read_file(current_fd, &read_res);
		res = ft_strjoin(res, buf);
	}
	if(ft_strchr(res, '\n'))
		*(res + ft_strchr(res, '\n')) = '\0';
	printf("res == %s\n", res);
	return (res);
}
