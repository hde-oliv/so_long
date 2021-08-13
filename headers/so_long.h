#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

/* map parsing */
typedef struct s_map
{
	int		height;
	int		width;
	t_list	*rows;
}	t_map;

bool	is_map(char *arg);
int		count_exits(char *row);
int		count_players(char *row);
int		count_collectibles(char *row);
bool	strcchr(char *s, char c);
bool	validate_row(char *row);
bool	validate_map(t_list *rows);
bool	validate_walls(t_list *rows);
t_map	*parse_map(int fd);

/* error functions */
# define EINVM "Invalid map.\n"
# define EIEMP "Empty map.\n"
# define EINAR "Invalid number of arguments.\n"
# define EINAM "The argument is not a map.\n"

void	error(const char *err_func);
void	r_error(const char *function);
void	invalid_map(t_list **rows);

#endif
