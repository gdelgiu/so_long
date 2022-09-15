/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 05:37:49 by aperrone          #+#    #+#             */
/*   Updated: 2022/03/16 05:37:51 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init(t_game *game)
{
	enemies_init(game);
	empty_init(game);
	wall_init(game);
	player_init(game);
	collectables_init(game);
	quit_init(game);
	enemies_movement(game);
	update_player_illegal(game);
}

int	update(t_game *game)
{
	char	*moves_count;

	wall_animation(game);
	enemies_animation(game);
	enemies_movement(game);
	mlx_clear_window(game->mlx, game->win->win);
	ft_draw_map(game);
	moves_count = ft_itoa(game->moves_count);
	mlx_string_put(game->mlx, game->win->win, 64, 64, 0xFFFFFF,
		moves_count);
	free(moves_count);
	return (1);
}

char	**build_map(t_game *game)
{
	t_tile	*tiles;
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (game->coordinates.y + 1));
	tiles = game->tiles;
	i = 0;
	while (i <= game->coordinates.y)
		map[i++] = malloc(sizeof(char ) * (game->coordinates.x + 1));
	while (tiles)
	{
		map[tiles->position.y][tiles->position.x] = tiles->type;
		map[tiles->position.y][tiles->position.x + 1] = 0;
		tiles = tiles->next_tile;
	}
	i = -1;
	while (++i <= game->coordinates.x)
		last_drop(map, game, i);
	return (map);
}

void	update_map(t_game *game, t_tile *tile, t_tiletype type)
{
	int	i;

	i = 0;
	game->map[tile->position.y][tile->position.x] = type;
	while (i < game->coordinates.y)
		i++;
}
