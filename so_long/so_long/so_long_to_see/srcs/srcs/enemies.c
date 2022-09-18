/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:45:42 by aperrone          #+#    #+#             */
/*   Updated: 2022/03/11 08:24:20 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	enemies_init(t_game *game)
{
	int						w;
	int						h;

	game->enemy = malloc(sizeof(t_enemy));
	game->enemy->img0 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/enemies/fire_0.xpm", &w, &h);
	game->enemy->img1 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/enemies/fire_1.xpm", &w, &h);
	game->enemy->img2 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/enemies/fire_2.xpm", &w, &h);
	game->enemy->img3 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/enemies/fire_3.xpm", &w, &h);
	game->enemy->img4 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/enemies/fire_4.xpm", &w, &h);
	game->enemy->img5 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/enemies/fire_5.xpm", &w, &h);
	game->enemy->action_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/enemies/fire_5.xpm", &w, &h);
	game->enemy->framecount = 0;
	game->enemy->idle_frames = 6;
	game->enemy->current_img = game->enemy->action_img;
}

void	enemies_animation(t_game *game)
{
	if (game->enemy->current_img == game->enemy->action_img
		&& game->enemy->framecount >= 0)
	game->enemy->current_img = game->enemy->img1;
	else if (game->enemy->framecount == game->enemy->idle_frames)
	game->enemy->current_img = game->enemy->img0;
	else if (game->enemy->framecount == game->enemy->idle_frames * 2)
	game->enemy->current_img = game->enemy->img2;
	else if (game->enemy->framecount == game->enemy->idle_frames * 2.2)
	game->enemy->current_img = game->enemy->img3;
	else if (game->enemy->framecount == game->enemy->idle_frames * 2.4)
	game->enemy->current_img = game->enemy->img4;
	else if (game->enemy->framecount == game->enemy->idle_frames * 2.6)
	game->enemy->current_img = game->enemy->img5;
	else if (game->enemy->framecount >= game->enemy->idle_frames * 2.8)
	{
		game->enemy->current_img = game->enemy->img1;
		game->enemy->framecount = 0;
	}
	game->enemy->framecount += 1;
}

void	enemies_movement(t_game *game)
{
	int						i;
	t_tile					*tile;
	static int				frames;

	tile = game->tiles;
	i = 0;
	if (!(frames % 35))
	{
		while (tile)
		{
			if (tile->type == ENEMY)
			{
				update_map(game, tile, EMPTY);
				update_enemies_illegal(game, tile);
				circle_(tile);
				update_enemies_illegal(game, tile);
				update_map(game, tile, ENEMY);
				i++;
			}
			tile = tile->next_tile;
		}
	}
	frames++;
}
