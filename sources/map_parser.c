#include "so_long.h"
#include "libft.h"

bool	row_validator(char *row)
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

bool	is_map(char *arg)
{
	char	*dot_location;

	dot_location = ft_strrchr(arg, '.');
	if (dot_location)
		return (!ft_strncmp(dot_location, ".ber", 4));
	return (false);
}

t_map	*map_parser(int fd)
{
	t_map	*game_map;
	char	*row;
	t_list	*rows;

	rows = NULL;
	while (get_next_line(fd, &row) == 1)
	{
		if (!row)
			error("malloc");
		else if (!row_validator(row))
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
