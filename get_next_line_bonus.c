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

#include "get_next_line_bonus.h"

static char	*read_file(int fd, char *static_str)
{
	char	*buf;
	char	*tmp;
	int		read_res;

	read_res = 1;
	buf = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (judge_null_free_strs(static_str, NULL));
	buf[BUFFER_SIZE] = '\0';
	while (!ft_strchr(static_str, '\n') && read_res != 0)
	{
		read_res = read(fd, buf, BUFFER_SIZE);
		if (read_res == -1)
			return (judge_null_free_strs(static_str, buf));
		buf[read_res] = '\0';
		tmp = static_str;
		static_str = ft_strjoin(static_str, buf);
		free(tmp);
	}
	free(buf);
	return (static_str);
}

static char	*cut_line(char *static_str)
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

static char	*update_static_str(char *static_str)
{
	char	*line_pointer;
	char	*new_static_str;

	if (!ft_strchr(static_str, '\n'))
		return (judge_null_free_strs(static_str, NULL));
	line_pointer = ft_strchr(static_str, '\n') + 1;
	new_static_str = ft_strdup(line_pointer);
	free(static_str);
	return (new_static_str);
}

char	*get_next_line(int fd)
{
	static char	*static_str[1024];
	char		*res;

	if ((fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	static_str[fd] = read_file(fd, static_str[fd]);
	if (!static_str[fd])
		return (NULL);
	res = cut_line(static_str[fd]);
	static_str[fd] = update_static_str(static_str[fd]);
	return (res);
}
