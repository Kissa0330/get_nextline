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

char	*get_next_line(int fd)
{
	static int	read_res = 1;
	static int	current_fd = 0;
	char		c;
	int			i;
	char		*res;

	if (current_fd != fd)
	{
		current_fd = fd;
		read_res = 1;
	}
	if (read_res == -1 || read_res == 0)
		return (NULL);
	i = 0;
	res = malloc(BUFFER_SIZE + 1);
	res[BUFFER_SIZE] = '\0';
	while (i < BUFFER_SIZE)
	{
		read_res = read(fd, &c, 1);
		if (read_res == 0 || read_res == -1)
			break;
		if (c == '\0')
			return (res);
		res[i] = c;
		if (c == '\n')
			return (res);
		i++;
	}
	if (read_res == -1)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
