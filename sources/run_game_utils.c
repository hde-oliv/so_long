/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hde-oliv <hde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 15:37:46 by hde-oliv          #+#    #+#             */
/*   Updated: 2021/09/02 15:37:46 by hde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

void	move_player_up(t_game *game, int *moves)
{
	if (valid_move(game, game->heroine_x, game->heroine_y - 1))
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->bg->ptr, game->heroine_x * 32, game->heroine_y * 32);
		game->heroine_y--;
		(*moves)++;
	}
}
void	move_player_down(t_game *game, int *moves)
{
	if (valid_move(game, game->heroine_x, game->heroine_y + 1))
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->bg->ptr, game->heroine_x * 32, game->heroine_y * 32);
		game->heroine_y++;
		(*moves)++;
	}
}
void	move_player_left(t_game *game, int *moves)
{
	if (valid_move(game, game->heroine_x - 1, game->heroine_y))
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->bg->ptr, game->heroine_x * 32, game->heroine_y * 32);
		game->heroine_x--;
		(*moves)++;
	}
}

void	move_player_right(t_game *game, int *moves)
{
	if (valid_move(game, game->heroine_x + 1, game->heroine_y))
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->bg->ptr, game->heroine_x * 32, game->heroine_y * 32);
		game->heroine_x++;
		(*moves)++;
	}
}

bool	valid_move(t_game *game, int wanted_x, int wanted_y)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = -1;
	tmp = game->map->rows;
	if (wanted_y >= game->map->height || !wanted_y)
		return (false);
	else if (wanted_x >= game->map->width || !wanted_x)
		return (false);
	while (i++ <= wanted_y && tmp)
	{
		j = -1;
		while (j++ <= wanted_x)
		{
			if (i == wanted_y && j == wanted_x)
			{
				if (((char *)(tmp->content))[j] != '1')
					return (true);
			}
		}
		tmp = tmp->next;
	}
	return (false);
}
