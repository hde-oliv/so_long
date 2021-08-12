#include "libft.h"
#include "mlx.h"
#include "so_long.h"

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


	// render_game
	// start_game
	// handle_game
	// end_game
	//  /* void	(*free_ptr)(void *); */
	//  /* free_ptr = &free; */
	//  /* ft_lstclear(&game_map->rows, free_ptr); */
	//  /* free(game_map); */
	return (0);
}
