/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:24:15 by aperrone          #+#    #+#             */
/*   Updated: 2022/01/24 19:45:21 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *saved_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!saved_str[i])
		return (NULL);
	while (saved_str[i] && saved_str[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (saved_str[i] && saved_str[i] != '\n')
	{
		str[i] = saved_str[i];
		i++;
	}
	if (saved_str[i] == '\n')
	{
		str[i] = saved_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_str = ft_res(fd, saved_str);
	if (!saved_str)
		return (NULL);
	line = ft_get_line(saved_str);
	saved_str = ft_save(saved_str);
	return (line);
}
