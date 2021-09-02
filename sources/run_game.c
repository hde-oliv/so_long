#include "so_long.h"
#include "mlx.h"

void	run_game(t_game *game)
{
	handle_player(game);
}

void	handle_player(t_game *game)
{
	refresh_player(game);
	mlx_hook(game->mlx_win, 2, 1L<<0, &move_player, game);
}

void	refresh_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->heroine->ptr, game->heroine_x * 32, game->heroine_y * 32);
}

int	move_player(int key, void *p)
{
	t_game		*game;
	static int	moves;

	game = (t_game *)p;
	if (key == 65362)
		move_player_up(game);
	else if (key == 65364)
		move_player_down(game);
	else if (key == 65361)
		move_player_left(game);
	else if (key == 65363)
		move_player_right(game);
	refresh_player(game);
	printf("Moves: %d\n", ++moves);
	return (0);
}
