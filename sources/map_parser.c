#include "so_long.h"
#include "libft.h"

bool	is_map(char *arg)
{
	char	*dot_location;

	dot_location = ft_strrchr(arg, '.');
	if (dot_location)
		return (ft_strncmp(dot_location, "ber", 3));
	return false;
}
