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

char	*read_file(int fd, char *static_str)
{
	char	*buf;
	char	*tmp;
	int		read_res;

	read_res = 1;
	buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		if (static_str)
			free(static_str);
		return (NULL);
	}
	buf[BUFFER_SIZE] = '\0';
	while (!ft_strchr(static_str, '\n') && read_res != 0)
	{
		read_res = read(fd, buf, BUFFER_SIZE);
		if (read_res == -1)
		{
			if (static_str)
				free(static_str);
			free(buf);
			return (NULL);
		}
		buf[read_res] = '\0';
		tmp = static_str;
		static_str = ft_strjoin(static_str, buf);
		free(tmp);
	}
	free(buf);
	return (static_str);
}

char	*cut_line(char *static_str)
{
	char	*res;
	size_t	i;

	if (!static_str[0])
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(static_str) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (static_str[i] != '\n' && static_str[i])
	{
		res[i] = static_str[i];
		i++;
	}
	if (static_str[i] == '\n')
	{
		res[i] = '\n';
		res[i + 1] = '\0';
	}
	else
		res[i] = '\0';
	return (res);
}

char	*update_static_str(char *static_str)
{
	char	*line_pointer;
	char	*new_static_str;

	if (!ft_strchr(static_str, '\n'))
	{
		free(static_str);
		return (NULL);
	}
	line_pointer = ft_strchr(static_str, '\n') + 1;
	new_static_str = ft_strdup(line_pointer);
	free(static_str);
	return (new_static_str);
}

char	*get_next_line(int fd)
{
	static char	*static_str = NULL;
	static int	current_fd = 1;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (current_fd != fd)
	{
		current_fd = fd;
		free(static_str);
		static_str = NULL;
	}
	static_str = read_file(current_fd, static_str);
	if (!static_str)
		return (NULL);
	res = cut_line(static_str);
	static_str = update_static_str(static_str);
	return (res);
}
