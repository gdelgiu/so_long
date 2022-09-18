/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 03:03:40 by aperrone          #+#    #+#             */
/*   Updated: 2022/02/17 03:03:45 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	main(int argc, char **argv)
{
	//t_game	game;
	t_map	*map;

	if (argc != 2 || get_map_from_file(argv[1], map))
	{
		ft_putstr("Invalid Arguments");
		return (1);
	}
	/*
	ft_init(argv[1], &game);
	game.map = build_map(&game);
	game.mlx = mlx_init();
	game.win->win = mlx_new_window(game.mlx,
			game.win->win_size.x * TILE_SIZE,
			game.win->win_size.y * TILE_SIZE, "Dante's Inferno");
	init(&game);
	mlx_do_key_autorepeaton(game.mlx);
	mlx_hook(game.win->win, 2, (1L << 0), deal_key, &game);
	mlx_hook(game.win->win, 17, 0, deal_close, &game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	*/
	return (0);
}
/*
int	deal_close(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win->win);
	exit(0);
	return (1);
}
*/