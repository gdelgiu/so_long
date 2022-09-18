/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 07:35:51 by aperrone          #+#    #+#             */
/*   Updated: 2022/03/26 20:32:56 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	make_bg(t_game *game)
{
	t_tile	*tiles;

	tiles = game->tiles;
	while (tiles)
	{
		if (tiles->type == '1')
		{
			mlx_put_image_to_window(game->mlx, game->win->win,
				game->wall->current_img, tiles->position.x * TILE_SIZE,
				tiles->position.y * TILE_SIZE);
		}
		else if (tiles->type == 'C')
			ft_draw_collectables(game, tiles->position);
		else
		{
			mlx_put_image_to_window(game->mlx, game->win->win,
				game->empty->img, tiles->position.x * TILE_SIZE,
				tiles->position.y * TILE_SIZE);
		}
		tiles = tiles->next_tile;
	}
}

void	ft_draw_map(t_game *game)
{
	int		i;
	t_tile	*tiles;

	tiles = game->tiles;
	i = 1;
	make_bg(game);
	tiles = game->tiles;
	while (tiles)
	{
		if (tiles->type == 'E')
			ft_draw_enemies(game, tiles->position);
		if (tiles->type == 'Q')
			ft_draw_quit(game, tiles->position);
		if (tiles->type == 'P')
			ft_draw_player(game, game->player->tile->position);
		tiles = tiles->next_tile;
		i++;
	}
}

void	ft_draw_collectables(t_game *game, t_vector pos)
{
	mlx_put_image_to_window(game->mlx, game->win->win,
		game->collectable->current_img, pos.x * TILE_SIZE,
		pos.y * TILE_SIZE);
}

void	ft_draw_enemies(t_game *game, t_vector pos)
{
	mlx_put_image_to_window(game->mlx, game->win->win,
		game->enemy->current_img, pos.x * TILE_SIZE,
		pos.y * TILE_SIZE);
}

void	ft_draw_player(t_game *game, t_vector pos)
{
	mlx_put_image_to_window(game->mlx, game->win->win,
		game->player->current_img, pos.x * TILE_SIZE,
		pos.y * TILE_SIZE);
}
