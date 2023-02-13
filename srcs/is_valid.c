#include "so_long.h"

void	ft_is_map_valid(t_game *game, int x, int y)
{
	if (game->map.matrix_clone[y][x] == 'C')
		game->tmp_collectible += 1;
	if (game->map.matrix_clone[y][x] == 'E')
		game->tmp_exit += 1;
	game->map.matrix_clone[y][x] = '.';
	if (game->map.matrix_clone[y][x - 1] != '1' && game->map.matrix_clone[y][x - 1] != '.'
		&& game->map.matrix_clone[y][x - 1] != 'P' && game->map.matrix_clone[y][x - 1] != 'E')
		ft_is_map_valid(game, x - 1, y);
	if (game->map.matrix_clone[y + 1][x] != '1' && game->map.matrix_clone[y + 1][x] != '.'
		&& game->map.matrix_clone[y + 1][x] != 'P' && game->map.matrix_clone[y + 1][x] != 'E')
		ft_is_map_valid(game, x, y + 1);
	if (game->map.matrix_clone[y - 1][x] != '1' && game->map.matrix_clone[y - 1][x] != '.'
		&& game->map.matrix_clone[y - 1][x] != 'P' && game->map.matrix_clone[y - 1][x] != 'P')
		ft_is_map_valid(game, x, y - 1);
	if (game->map.matrix_clone[y][x + 1] != '1' && game->map.matrix_clone[y][x + 1] != '.'
		&& game->map.matrix_clone[y][x + 1] != 'P' && game->map.matrix_clone[y][x + 1] != 'E')
		ft_is_map_valid(game, x + 1, y);
	else
	{
		game->map.matrix_clone[y][x] = '.';
		return ;
	}
}

int	ft_is_map_valid2(t_game *game, int i, int j)
{
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.matrix_clone[i][j] == 'C')
				return 0;
			if (game->map.matrix_clone[i][j] == 'E')
				return 0;
			j++;
		}
		i++;
	}
	return 1;
}

int	ft_map_name_check(char *path)
{
	int		i;
	char *ber;
	char *txt;
	int j;

	j = 0;
	ber = ".ber";
	i = ft_strlen(path);
	txt = ft_substr(path, i - 4, 4);
	if (txt == ber)
		j = 1;
	free(txt);
	return (j);
}

