#include "so_long.h"
#include "libft.h"

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
		rows = rows->next;
	}
	if (!collectibles || !exits || !players)
		return (false);
	return (true);
}
