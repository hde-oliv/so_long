#include "so_long.h"
#include "libft.h"

static int	count_exits(char *row)
{
	int	answer;

	answer = 0;
	while (*row)
	{
		if (*row == 'E')
			answer++;
		row++;
	}
	return (answer);
}

static int	count_players(char *row)
{
	int	answer;

	answer = 0;
	while (*row)
	{
		if (*row == 'P')
			answer++;
		row++;
	}
	return (answer);
}

static int	count_collectibles(char *row)
{
	int	answer;

	answer = 0;
	while (*row)
	{
		if (*row == 'C')
			answer++;
		row++;
	}
	return (answer);
}

bool	validate_map(t_list *rows)
{
	static int	collectibles;
	static int	exits;
	static int	players;
	static int	row_size;
	int			tmp_size;

	while (rows->next)
	{
		if (!row_size)
			row_size = ft_strlen(rows->content);
		tmp_size = ft_strlen(rows->content);
		if (tmp_size != row_size)
			return (false);
		exits += count_exits(rows->content);
		players += count_players(rows->content);
		collectibles += count_collectibles(rows->content);
		rows = rows->next;
	}
	if (!collectibles || !exits || !players)
		return (false);
	return (true);
}
