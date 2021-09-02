/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:23:37 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/02 17:24:26 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

/* map parsing */
typedef struct s_map
{
	int		height;
	int		width;
	t_list	*rows;
}	t_map;

bool	is_map(char *arg);
int		count_exits(char *row);
int		count_players(char *row);
int		count_collectibles(char *row);
bool	strcchr(char *s, char c);
bool	validate_row(char *row);
bool	validate_map(t_list *rows);
bool	validate_walls(t_list *rows);
t_map	*parse_map(int fd);

/* create_game */
# define CLOSE_W 17

typedef struct s_img
{
	void	*ptr;
	char	*pixels;
	int		bpp;
	int		line_size;
	int		endian;
	int		x;
	int		y;
}	t_img;

typedef struct s_game
{
	t_map	*map;
	void	*mlx;
	void	*mlx_win;
	t_img	*heroine;
	t_img	*wall;
	t_img	*bg;
	t_img	*coin;
	t_img	*exit;
	int		coins;
	int		heroine_x;
	int		heroine_y;
}	t_game;

void	create_game(t_game *game);
void	allocate_sprites(t_game *game);
void	set_collectibles_quantity(t_game *game);
void	create_images(t_game *game);
void	put_image(t_game *game, char pos, int x, int y);
void	make_map(t_game *game);
void	*wrap_xpm(t_game *game, char *filename, t_img *img);
void	*wrap_data(t_img *img);

/* run game */
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307
# define X_BUTTON_EV 17
# define NO_MASK 0L
# define KEY_PRESS_EV 2
# define KEY_PRESS_MASK 1L

void	run_game(t_game *game);
int		handle_keys(int key, void *p);
void	refresh_player(t_game *game);
bool	valid_move(t_game *game, int wanted_x, int wanted_y, char *pos);
bool	is_wall(t_game *game, int wanted_x, int wanted_y);
void	move_player_up(t_game *game, int *moves);
void	move_player_down(t_game *game, int *moves);
void	move_player_left(t_game *game, int *moves);
void	move_player_right(t_game *game, int *moves);
void	end_game(t_game *game);
int		handle_buttons(void *p);

/* error handling */
# define EINVM "Invalid map.\n"
# define EIEMP "Empty map.\n"
# define EINAR "Invalid number of arguments.\n"
# define EINAM "The argument is not a map.\n"

void	error(const char *err_func);
void	r_error(const char *function);
void	invalid_map(t_list **rows);
#endif
