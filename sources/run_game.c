/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:39:23 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/02 17:18:04 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"
#include "mlx.h"

void	run_game(t_game *game)
{
	refresh_player(game);
	mlx_hook(game->mlx_win, KEY_PRESS_EV, KEY_PRESS_MASK, &handle_keys, game);
	mlx_hook(game->mlx_win, X_BUTTON_EV, NO_MASK, &handle_buttons, game);
}

void	refresh_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, \
							game->mlx_win, \
							game->heroine->ptr, \
							game->heroine_x * 16, \
							game->heroine_y * 16);
}

int	handle_keys(int key, void *p)
{
	t_game		*game;
	static int	moves;

	game = (t_game *)p;
	if (key == W_KEY)
		move_player_up(game, &moves);
	else if (key == S_KEY)
		move_player_down(game, &moves);
	else if (key == A_KEY)
		move_player_left(game, &moves);
	else if (key == D_KEY)
		move_player_right(game, &moves);
	else if (key == ESC_KEY)
		end_game(game);
	refresh_player(game);
	printf("Moves: %d | Remaining Coins: %d\n", moves, game->coins);
	return (0);
}

int	handle_buttons(void *p)
{
	t_game		*game;

	game = (t_game *)p;
	end_game(game);
	return (0);
}

void	end_game(t_game *game)
{
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->heroine->ptr);
	mlx_destroy_image(game->mlx, game->bg->ptr);
	mlx_destroy_image(game->mlx, game->exit->ptr);
	mlx_destroy_image(game->mlx, game->wall->ptr);
	mlx_destroy_image(game->mlx, game->coin->ptr);
	free(game->heroine);
	free(game->bg);
	free(game->exit);
	free(game->wall);
	free(game->coin);
	ft_lstclear(&game->map->rows, &free);
	free(game->map);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
