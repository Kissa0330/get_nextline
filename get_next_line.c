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

char	*read_file(int fd)
{
	char	*buf;
	char	*res;
	int		read_res;
	size_t	i;

	res = NULL;
	read_res = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	buf[BUFFER_SIZE] = '\0';
	while (!ft_strchr(buf, '\n') && read_res != 0)
	{
		read_res = read(fd, buf, BUFFER_SIZE);
		i = 0;
		if (read_res == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_res] = '\0';
		// printf("read_res == %d\n", read_res);
		// printf("buf == %s\n", buf);
		// printf("befor res == %s\n", res);
		res = ft_strjoin(res, buf);
		// printf("res == %s\n", res);
		i ++;
	}
	return (res);
}

char	*cut_line(char *static_str)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char) * ft_strlen(static_str) + 1);
	i = 0;
	while (static_str[i] != '\n' && static_str[i])
	{
		res[i] = static_str[i];
		i++;
	}
	if(static_str[i] == '\n')
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
	char	*new_static_str;
	char	*line_pointer;

	if(!ft_strchr(static_str, '\n'))
		return (NULL);
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
	char		*buf;

	res = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(current_fd != fd)
	{
		current_fd = fd;
		free(static_str);
		static_str = NULL;
	}
	buf = read_file(fd);
	// printf("buf == %s\n", buf);
	static_str = ft_strjoin(static_str, buf); //static_strとbufをfreeする
	// printf("static_str == %s\n", static_str);
	if(static_str == NULL || static_str[0] == '\0')
		return (NULL);
	res = cut_line(static_str);
	// printf("res == %s\n", res);
	static_str = update_static_str(static_str);
	// printf("updated_static_str == %s\n", static_str);
	return (res);
}
