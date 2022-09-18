/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 21:26:41 by aperrone          #+#    #+#             */
/*   Updated: 2022/02/21 21:26:43 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	wall_init(t_game *game)
{
	int	w;
	int	h;

	game->wall = malloc(sizeof(t_wall));
	game->wall->img0 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/walls/lava_0.xpm", &w, &h);
	game->wall->img1 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/walls/lava_1.xpm", &w, &h);
	game->wall->img2 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/walls/lava_2.xpm", &w, &h);
	game->wall->img3 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/walls/lava_3.xpm", &w, &h);
	game->wall->img4 = mlx_xpm_file_to_image(game->mlx,
			"./sprites/walls/lava_4.xpm", &w, &h);
	game->wall->action_img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/walls/lava_0.xpm", &w, &h);
	game->wall->framecount = 0;
	game->wall->idle_frames = 500;
	game->wall->current_img = game->wall->action_img;
}

void	wall_animation(t_game *game)
{
	if (game->wall->current_img == game->wall->action_img
		&& game->wall->framecount >= 0)
	game->wall->current_img = game->wall->img0;
	else if (game->wall->framecount == game->wall->idle_frames)
		game->wall->current_img = game->wall->img1;
	else if (game->wall->framecount == game->wall->idle_frames * 1.2)
		game->wall->current_img = game->wall->img2;
	else if (game->wall->framecount == game->wall->idle_frames * 1.4)
		game->wall->current_img = game->wall->img3;
	else if (game->wall->framecount == game->wall->idle_frames * 1.6)
		game->wall->current_img = game->wall->img4;
	else if (game->wall->framecount == game->wall->idle_frames * 1.8)
		game->wall->current_img = game->wall->img4;
	else if (game->wall->framecount == game->wall->idle_frames * 2.0)
		game->wall->current_img = game->wall->img3;
	else if (game->wall->framecount == game->wall->idle_frames * 2.2)
		game->wall->current_img = game->wall->img2;
	else if (game->wall->framecount == game->wall->idle_frames * 2.4)
		game->wall->current_img = game->wall->img1;
	else if (game->wall->framecount >= game->wall->idle_frames * 2.6)
	{
		game->wall->current_img = game->wall->img0;
		game->wall->framecount = 0;
	}
	game->wall->framecount += 1;
}

void	add_wall(t_game *game)
{
	ft_add_in_tail(ft_lstlast(game->tiles), WALL, game->coordinates);
	game->n_walls++;
}
