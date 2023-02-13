#include "so_long.h"

void ft_check_map(t_game *game)
{
	int i;

	i = 0;
	while (i < game->map.width)
	{
		if (game->map.matrix[game->map.height - 1][i]|| game->map.matrix[0][i] != '1')
		{
			ft_printf("Map is not closed correctly");
			exit(1);
		}
		i++;
	}
}

void ft_countmap(t_game *game)
{
	char	*read;
	int		fd;
	int tmp;

	game->map.height = 0;
	fd = open(game->map.ber, O_RDONLY);
	read = get_next_line(fd);
	game->map.width = ft_strlen(read) - 1;
	while (read)
	{
		game->map.height++;
		free(read);
		read = get_next_line(fd);
		if (read)
			tmp = ft_strlen(read) - 1;
		if (tmp != game->map.width)
		{
			ft_printf("Map is not a rectangle");
			exit(1);
		}
	}
	free(read);
}

char **ft_readmap(t_game *game)
{
	int		fd;
	int		i;
	char **rtn;

	rtn = malloc(sizeof(char *) * game->map.height);
	fd = open(game->map.ber, O_RDONLY);
	i = 0;
	while (i < game->map.height)
	{
		rtn[i] = get_next_line(fd);
		i++;
	}
	return (rtn);
}

void ft_findplayer(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.matrix[i][j] == 'P')
			{
				game->p.x = i*64;
				game->p.y = j*64;
				return ;
			}
			j++;
		}
		i++;
	}
}

void ft_check_anime_girls(t_game *game)
{
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.matrix[i][j] == 'C')
			{
				if (k == 0)
					game->map.matrix[i][j] = 'H';
				else if (k == 1)
					game->map.matrix[i][j] = 'J';
				else if (k == 2)
					game->map.matrix[i][j] = 'K';
				else if (k == 3)
					game->map.matrix[i][j] = 'L';
				k++;
				if (k % 4 == 0)
					k = 0;
			}
			j++;
		}
		i++;
	}
}

int ft_exitmap(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

