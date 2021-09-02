/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:39:23 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/02 15:39:23 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	run_game(t_game *game)
{
	refresh_player(game);
	mlx_hook(game->mlx_win, 2, 1L<<0, &move_player, game);
}

void	refresh_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, \
							game->mlx_win, \
							game->heroine->ptr, \
							game->heroine_x * 32, \
							game->heroine_y * 32);
}

int	move_player(int key, void *p)
{
	t_game		*game;
	static int	moves;

	game = (t_game *)p;
	if (key == 65362)
		move_player_up(game, &moves);
	else if (key == 65364)
		move_player_down(game, &moves);
	else if (key == 65361)
		move_player_left(game, &moves);
	else if (key == 65363)
		move_player_right(game, &moves);
	refresh_player(game);
	printf("Moves: %d\n", moves);
	return (0);
}
