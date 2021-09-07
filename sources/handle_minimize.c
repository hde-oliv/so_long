#include "so_long.h"
#include "mlx.h"

static void	put_image_(t_game *game, char pos, int x, int y)
{
	if (pos == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->wall->ptr, x * 16, y * 16);
	else if (pos == '0' || pos == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->bg->ptr, x * 16, y * 16);
	else if (pos == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->coin->ptr, x * 16, y * 16);
	else if (pos == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
								game->exit->ptr, x * 16, y * 16);
}

static void	make_map_(t_game *game)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = -1;
	tmp = game->map->rows;
	while (i++ < game->map->height && tmp)
	{
		j = -1;
		while (j++ < game->map->width)
		{
			put_image_(game, ((char *)(tmp->content))[j], j, i);
		}
		tmp = tmp->next;
	}
}

int	handle_focus(void *p)
{
	t_game *game;

	game = (t_game *) p;
	make_map_(game);
	refresh_player(game);
	return (0);
}

int	handle_minimize(void *p)
{
	t_game *game;

	game = (t_game *) p;
	make_map_(game);
	refresh_player(game);
	return (0);
}


