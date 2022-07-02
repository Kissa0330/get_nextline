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

char	*ft_strdup(const char *src)
{
	char	*copy_str;
	int		i;

	copy_str = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (copy_str == NULL)
		return (copy_str);
	i = 0;
	while (*(src + i) != '\0')
	{
		*(copy_str + i) = *(src + i);
		i++;
	}
	*(copy_str + i) = '\0';
	return (copy_str);
}


char	*ft_strchr(char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return (s);
}

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

void	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count1;
	size_t	count2;

	count1 = ft_strlen(dest);
	count2 = 0;
	while (src[count2] != '\0' && count1 + count2 < size - 1)
	{
		dest[count1 + count2] = src[count2];
		count2++;
	}
	dest[count1 + count2] = '\0';
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	length;
	char	*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	length = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (length + 1));
	str[length] = '\0';
	if (str == NULL)
		return (NULL);
	ft_strlcat(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, length + 1);
	return (str);
}
