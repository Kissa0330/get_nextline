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

char	*get_next_line(int fd)
{
	static int	read_res;
	char		c;
	int			i;
	char		*res;

	read_res = 1;
	i = 0;
	if (read_res == 0)
		return (NULL);
	res = malloc(BUFFER_SIZE + 1);
	while (i < BUFFER_SIZE)
	{
		read_res = read(fd, &c, 1);
		if (read_res == 0)
			return (res);
		if (c == '\0')
			return (res);
		res[i] = c;
		if (c == '\n')
			return (res);
		i++;
	}
	res[BUFFER_SIZE] = '\0';
	return (res);
}
