#include "so_long.h"
#include "libft.h"

int	count_exits(char *row)
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

int	count_players(char *row)
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

int	count_collectibles(char *row)
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

bool	is_map(char *arg)
{
	char	*dot_location;

	dot_location = ft_strrchr(arg, '.');
	if (dot_location)
		return (!ft_strncmp(dot_location, ".ber", 4));
	return (false);
}
