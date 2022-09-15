/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 03:05:30 by aperrone          #+#    #+#             */
/*   Updated: 2022/02/17 03:05:32 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_init(char *path, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	init_var(game);
	ft_init_win(game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (check_map(game, line))
			break ;
		game->coordinates.x = 0;
		while (line[game->coordinates.x] != '\0')
		{
			ft_add_tiletype(line[game->coordinates.x], game);
			game->coordinates.x++;
		}
		game->coordinates.y++;
		free (line);
		line = get_next_line(fd);
	}
	last_check(game);
	ft_set_win(game);
	close (fd);
}

void	ft_init_win(t_game *game)
{
	game->win = malloc(sizeof(t_win));
	game->win->win_size.x = -1;
}

void	ft_set_win(t_game *game)
{
	game->win->win_size.x = game->coordinates.x - 1;
	game->win->win_size.y = game->coordinates.y;
}

void	init_var(t_game *game)
{
	game->coordinates.y = 0;
	game->n_collectables = 0;
	game->n_walls = 0;
	game->n_empty = 0;
	game->n_player = 0;
	game->n_quit = 0;
	game->flag_collect = 0;
	game->flag_quit = 0;
	game->moves_count = 0;
}

void	last_check(t_game *game)
{
	check_square(game->coordinates.x - 1, game->coordinates.y);
	check_onerow(game->coordinates.y);
	check_ultimate(game);
}
