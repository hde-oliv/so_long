#include "so_long.h"
#include "libft.h"

t_map	*parse_map(int fd)
{
	t_map	*game_map;
	char	*row;
	t_list	*rows;

	rows = NULL;
	while (get_next_line(fd, &row) == 1)
	{
		if (!row)
			error("malloc");
		else if (!validate_row(row))
			invalid_map(&rows);
		ft_lstadd_back(&rows, ft_lstnew(row));
	}
	game_map = (t_map *) malloc(sizeof(t_map));
	if (!game_map)
		error("malloc");
	game_map->width = ft_strlen(row);
	game_map->height = ft_lstsize(rows);
	game_map->rows = rows;
	free(row);
	return (game_map);
}

bool	validate_row(char *row)
{
	static int	fixed_len;
	int			len;

	if (!fixed_len)
		fixed_len = ft_strlen(row);
	len = ft_strlen(row);
	if (len != fixed_len || fixed_len < 3)
		return (false);
	while (len--)
	{
		if (row[len] == 'C' || row[len] == 'E' || row[len] == 'P' || \
			row[len] == '0' || row[len] == '1')
			continue ;
		else
			return (false);
	}
	return (true);
}

bool	validate_map(t_list *rows)
{
	static int	collectibles;
	static int	exits;
	static int	players;

	while (rows)
	{
		exits += count_exits(rows->content);
		players += count_players(rows->content);
		collectibles += count_collectibles(rows->content);
		rows = rows->next;
	}
	if (!collectibles || !exits || !players)
		return (false);
	return (true);
}
