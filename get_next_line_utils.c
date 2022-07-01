/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:48:24 by rtakano           #+#    #+#             */
/*   Updated: 2022/06/19 19:48:24 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	init_static_val(int *current_fd, int fd, int *read_res)
{
	if (*current_fd != fd)
	{
		*current_fd = fd;
		*read_res = 1;
	}
}

char	*read_file(int fd, int *read_res)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(BUFFER_SIZE + 1);
	if (res == NULL)
		return (NULL);
	res[BUFFER_SIZE] = '\0';
	while (i < BUFFER_SIZE)
	{
		*read_res = read(fd, res + i, 1);
		if (*read_res == -1)
		{
			free(res);
			return (NULL);
		}
		if (*read_res == 0 || res[i] == '\n')
			return (res);
		i++;
	}
	if (i + 1 == BUFFER_SIZE)
		res[i] = '\n';
	return (res);
}
