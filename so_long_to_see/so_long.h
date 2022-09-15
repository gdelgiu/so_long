/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperrone <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 03:04:02 by aperrone          #+#    #+#             */
/*   Updated: 2022/02/17 03:04:05 by aperrone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 64

# include "srcs/minilibx_mms_/mlx.h"
# include "srcs/getnextline/get_next_line.h"

# include <stdio.h>
# include <fcntl.h>

typedef struct s_illegal_actions
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_illegal_actions;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_win
{
	void		*win;
	t_vector	win_size;
}	t_win;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	PLAYER = 'P',
	COLLECTABLE = 'C',
	ENEMY = 'E',
	QUIT = 'Q'
}	t_tiletype;

typedef struct s_tiles
{
	t_tiletype			type;
	t_vector			position;
	t_illegal_actions	illegals;

	struct s_tiles		*next_tile;
}	t_tile;

typedef struct s_player
{
	t_tile				*tile;
	t_illegal_actions	illegals;
	void				*current_img;
	void				*action_img;
	int					framecount;
	int					actionframe;
}	t_player;

typedef struct s_enemy
{
	t_tile	*tile;
	void	*img0;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*current_img;
	void	*action_img;
	int		framecount;
	int		idle_frames;
}	t_enemy;

typedef struct s_empty
{
	void	*img;
}	t_empty;

typedef struct t_quit
{
	void	*img;
}	t_quit;

typedef struct s_collectables
{
	void	*current_img;
}	t_collectables;

typedef struct s_wall
{
	void	*img0;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*current_img;
	void	*action_img;
	int		framecount;
	int		idle_frames;
}	t_wall;

typedef struct s_game
{
	void			*mlx;
	char			**map;
	int				flag_collect;
	int				flag_quit;
	int				n_collectables;
	int				n_walls;
	int				n_empty;
	int				n_player;
	int				n_quit;
	int				moves_count;
	t_quit			*quit;
	t_collectables	*collectable;
	t_win			*win;
	t_vector		coordinates;
	t_tile			*tiles;
	t_wall			*wall;
	t_empty			*empty;
	t_player		*player;
	t_enemy			*enemy;
}	t_game;

typedef struct s_map {
	char	**data_matrix;
	int		width;
	int		height;
}	t_map;

//check_collision.c
void	p_static_collisions(t_game *game);
void	e_static_collisions(t_game *game, t_tile *enemy);
void	p_dinamic_collisions(t_game *game);
void	e_dinamic_collisions(t_game *game, t_tile *enemy);
void	p_wall_collisions(t_game *game);
//collectables.c
void	collectables_init(t_game *game);
void	check_ultimate(t_game *game);
//draw_map.c
void	make_bg(t_game *game);
void	ft_draw_map(t_game *game);
void	ft_draw_collectables(t_game *game, t_vector pos);
void	ft_draw_enemies(t_game *game, t_vector pos);
void	ft_draw_player(t_game *game, t_vector pos);
//empty.c
void	empty_init(t_game *game);
void	add_empty(t_game *game);
//enemies_collider.c
char	up(t_game *game, t_tile *enemy);
char	down(t_game *game, t_tile *enemy);
char	left(t_game *game, t_tile *enemy);
char	right(t_game *game, t_tile *enemy);
//enemies.c
void	enemies_init(t_game *enemy);
void	enemies_animation(t_game *game);
void	enemies_movement(t_game *game);
//ft_itoa.c
char	*ft_itoa(int n);
void	ft_putstr(char *str);
//handle_errors.c
int		check_map(t_game *game, char *line);
int		check_position(t_vector a, t_vector b);
int		check_char_map(char *line);
void	check_square(int x, int y);
void	check_onerow(int y);
//handle_nodes.c
char	ft_add_tiletype(char c, t_game *game);
t_tile	*ft_newnode(t_tiletype type, t_vector coordinates);
t_tile	*ft_add_in_tail(t_tile *tail, t_tiletype t, t_vector v);
t_tile	*ft_lstlast(t_tile *tile);
//init.c
void	init(t_game *game);
int		update(t_game *game);
char	**build_map(t_game *game);
void	update_map(t_game *game, t_tile *tile, t_tiletype type);
int		deal_close(t_game *game);
//key_management.c
void	ft_dokey(int key, t_game *game);
int		ft_iskey(int key);
int		deal_key(int key, t_game *game);
//movements.c
void	circle_(t_tile *tile);
//player_collider.c
char	p_up(t_game *game);
char	p_down(t_game *game);
char	p_left(t_game *game);
char	p_right(t_game *game);
void	add_player(t_game *game);
//player_movents.c
void	player_up(t_game *game);
void	player_down(t_game *game);
void	player_left(t_game *game);
void	player_right(t_game *game);
void	ft_putnbr2(int nbr);
//player.c
void	player_init(t_game *game);
void	player_up_img(t_game *game);
void	player_down_img(t_game *game);
void	player_left_img(t_game *game);
void	player_right_img(t_game *game);
//quit.c
void	quit_init(t_game *game);
void	ft_draw_quit(t_game *game, t_vector pos);
void	add_quit(t_game *game);
void	p_quit_collisions(t_game *game);
//read_file.c
void	ft_init(char *path, t_game *game);
void	ft_init_win(t_game *game);
void	ft_set_win(t_game *game);
void	init_var(t_game *game);
void	last_check(t_game *game);
//update_illegals.c
void	update_player_illegal(t_game *game);
void	update_enemies_illegal(t_game *game, t_tile *enemy);
void	last_drop(char **map, t_game *game, int i);
//wall.c
void	wall_init(t_game *game);
void	wall_animation(t_game *game);
void	add_wall(t_game *game);

int		precheck(t_map map);
int		get_map_from_file(char *file_name, t_map map);

#endif