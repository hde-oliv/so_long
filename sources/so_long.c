#include "libft.h"
#include "mlx.h"
#include "so_long.h"

/*
** parse_map: OK
** render_game: TODO
** start_game: TODO
** handle_game: TODO
** end_game: TODO
*/

int	main(int argc, char *argv[])
{
	t_map	*game_map;
	int		map_fd;

	if (argc != 2)
		error("main");
	if (!is_map(argv[1]))
		error("is_map");
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd == -1)
		error("open");
	game_map = parse_map(map_fd);
	return (0);
}
