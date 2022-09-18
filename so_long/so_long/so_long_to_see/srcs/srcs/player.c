/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 09:49:17 by aperrone          #+#    #+#             */
/*   Updated: 2022/02/22 09:49:22 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	player_init(t_game *game)
{
	t_tile	*tiles;

	game->player = malloc(sizeof(t_player));
	tiles = game->tiles;
	while (tiles->type != 'P')
		tiles = tiles->next_tile;
	game->player->tile = malloc(sizeof(t_tile));
	game->player->tile->position = tiles->position;
	game->player->tile->type = tiles->type;
	if (game->player->tile->position.x == 0
		|| game->player->tile->position.y == 0)
	{
		ft_putstr("Invalid Map");
		exit (0);
	}
	player_down_img(game);
	game->player->current_img = game->player->action_img;
}

void	player_up_img(t_game *game)
{
	int		w;
	int		h;

	game->player->action_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/player/player_up.xpm", &w, &h);
	game->player->current_img = game->player->action_img;
}

void	player_down_img(t_game *game)
{
	int		w;
	int		h;

	if (game->flag_collect == 0)
		game->player->action_img = mlx_xpm_file_to_image(game->mlx,
				"./sprites/player/player_down.xpm", &w, &h);
	else
		game->player->action_img = mlx_xpm_file_to_image(game->mlx,
				"./sprites/player/player_down_collect.xpm", &w, &h);
	game->player->current_img = game->player->action_img;
}

void	player_left_img(t_game *game)
{
	int		w;
	int		h;

	if (game->flag_collect == 0)
		game->player->action_img = mlx_xpm_file_to_image(game->mlx,
				"./sprites/player/player_left.xpm", &w, &h);
	else
		game->player->action_img = mlx_xpm_file_to_image(game->mlx,
				"./sprites/player/player_left_collect.xpm", &w, &h);
	game->player->current_img = game->player->action_img;
}

void	player_right_img(t_game *game)
{
	int		w;
	int		h;

	if (game->flag_collect == 0)
		game->player->action_img = mlx_xpm_file_to_image(game->mlx,
				"./sprites/player/player_right.xpm", &w, &h);
	else
		game->player->action_img = mlx_xpm_file_to_image(game->mlx,
				"./sprites/player/player_right_collect.xpm", &w, &h);
	game->player->current_img = game->player->action_img;
}
