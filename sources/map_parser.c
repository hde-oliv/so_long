#include "so_long.h"
#include "libft.h"

bool	row_validator(char *row)
{
	int	len;

	len = ft_strlen(row);
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
