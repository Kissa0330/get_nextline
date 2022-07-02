/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakano   <rtakano@student.42.fr    >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:48:14 by rtakano           #+#    #+#             */
/*   Updated: 2022/07/01 00:24:50 by rtakano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
char	*read_file(int fd, int *read_res);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*free_strs(char *str1, char *str2);

#endif