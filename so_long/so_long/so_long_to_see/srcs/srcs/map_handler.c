/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdel-giu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:03:48 by gdel-giu          #+#    #+#             */
/*   Updated: 2022/08/15 17:53:08 by gdel-giu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <fcntl.h>

char	*get_row(int fd)
{
	char	*row;
	char	*buffer;
	int		char_read;

	row = "";
	buffer = (char *) malloc(2);
	char_read = read(fd, buffer, 1);
	while (char_read > 0)
	{
		row = ft_strjoin(row, buffer);
		char_read = read(fd, buffer, 1);
		if (char_read < 0)
			return (NULL);
		if (buffer[0] == '\n')
		{
			row = ft_strjoin(row, buffer);
			break ;
		}
	}
	free(buffer);
	return (row);
}

int	row_len(char *row)
{
	int	len;

	len = ft_strlen(row);
	if (ft_strchr(row, '\n'))
		len -= 1;
	return (len);
}

static char	*parse_to_str(int f_d, int *h, int *w)
{
	char	*temp;
	char	*map_str;

	temp = get_row(f_d);
	map_str = "";
	*h = 0;
	*w = row_len(temp);
	while (temp[0])
	{
		*h += 1;
		map_str = ft_strjoin(map_str, temp);
		ft_bzero(temp, ft_strlen(temp));
		free(temp);
		temp = get_row(f_d);
		if (temp[0] != '\0' && *w != row_len(temp))
		{
			free(map_str);
			map_str = NULL;
			break ;
		}
	}
	return (map_str);
}

void	make_matrix(int f_d, t_map *m)
{
	char	*parsed_str;

	m->data_matrix = NULL;
	parsed_str = parse_to_str(f_d, &(m->height), &(m->width));
	if (parsed_str[0] != '\0')
	{
		m->data_matrix = ft_split(parsed_str, '\n');
		if (parsed_str != NULL)
			free(parsed_str);
	}
}

int	get_map_from_file(char *file_name, t_map *map)
{
	int	fd;

	map = (t_map *) malloc(sizeof(t_map));
	if (!ft_strnstr(file_name, "ber", ft_strlen(file_name)))
	{
		map->data_matrix = NULL;
		return ;
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		(*map)->data_matrix = NULL;
		return ;
	}
	make_matrix(fd, *map);
	close(fd);
	return (precheck(*map));
}
