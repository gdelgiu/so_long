/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 07:27:02 by aperrone          #+#    #+#             */
/*   Updated: 2022/03/14 07:27:07 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	quit_init(t_game *game)
{
	int	w;
	int	h;

	game->quit = malloc(sizeof(t_quit));
	game->quit->img = mlx_xpm_file_to_image(game->mlx,
			"./sprites/quit/quit.xpm", &w, &h);
}

void	ft_draw_quit(t_game *game, t_vector pos)
{
	mlx_put_image_to_window(game->mlx, game->win->win,
		game->quit->img, pos.x * TILE_SIZE,
		pos.y * TILE_SIZE);
}

void	add_quit(t_game *game)
{
	ft_add_in_tail(ft_lstlast(game->tiles), QUIT, game->coordinates);
	game->n_quit++;
}

void	p_quit_collisions(t_game *game)
{
	if (p_up(game) == 'Q' && !game->flag_quit)
		game->player->illegals.up = 0;
	if (p_down(game) == 'Q' && !game->flag_quit)
		game->player->illegals.down = 0;
	if (p_left(game) == 'Q' && !game->flag_quit)
		game->player->illegals.left = 0;
	if (p_right(game) == 'Q' && !game->flag_quit)
		game->player->illegals.right = 0;
}
