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

char	*read_file(int fd, int *is_continue)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[BUFFER_SIZE] = '\0';
	while (i < BUFFER_SIZE)
	{
		*is_continue = read(fd, res + i, 1);
		if (res[i] == '\n')
		{
			*is_continue = 0;
			return (res);
		}
		if (*is_continue < 1)
			return (res);
		i ++;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static int	is_continue = 1;
	static int	current_fd = 0;
	char		*res;
	char		*buf;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (current_fd != fd)
	{
		current_fd = fd;
		is_continue = 1;
	}
	if (is_continue < 1)
		return (NULL);
	while (is_continue > 0)
	{
		buf = read_file(current_fd, &is_continue);
		res = ft_strjoin(res, buf);
	}
	return (res);
}
