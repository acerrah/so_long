#include "so_long.h"

int ft_looprender(t_game *game)
{
	ft_render(game);
	return (0);
}

void ft_player_idle(t_game *game)
{
	static int i = 0;
	if (game->p.facing == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->tex.mc_idle_r[i], game->p.y, game->p.x);
	else if(game->p.facing == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->tex.mc_idle_l[i], game->p.y, game->p.x);
	i++;
	if (i % 8 == 0)
		i = 0;
	usleep(10000);
}

void ft_check_data(t_game *game)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	game->data.C = 0;
	game->data.E = 0;
	game->data.X = 0;
	while (i < game->map.height)
	{
		j=0;
		while (j < game->map.width)
		{
			if (game->map.matrix[i][j] == 'J' || game->map.matrix[i][j] == 'H' || game->map.matrix[i][j] == 'K' || game->map.matrix[i][j] == 'L')
				game->data.C++;
			if (game->map.matrix[i][j] == 'E')
				game->data.E++;
			if (game->map.matrix[i][j] == 'X')
				game->data.X++;
			j++;
		}
		i++;
	}
	game->data.enemy_loc = malloc(sizeof(int *) * game->data.X);
	i = 0;
	while (i < game->map.height)
	{
		j=0;
		while (j < game->map.width)
		{
			if (game->map.matrix[i][j] == 'X')
			{
				game->data.enemy_loc[k] = malloc(sizeof(int) * 3);
				game->data.enemy_loc[k][0] = i*64;
				game->data.enemy_loc[k][1] = j*64;	
				game->data.enemy_loc[k][2] = 0;	
				k++;
			}
			j++;
		}
		i++;
	}


}

void ft_enemy_patrol(t_game *game, int i, int k)
{
	if (game->data.enemy_loc[i][2] == 0)
	{
		if (game->map.matrix[game->data.enemy_loc[i][0]/64][game->data.enemy_loc[i][1]/64 + 1] == '0'
			 || game->map.matrix[game->data.enemy_loc[i][0]/64][game->data.enemy_loc[i][1]/64 + 1] == 'P')
			game->data.enemy_loc[i][1] += 16;
		else
		{
			game->data.enemy_loc[i][2] = 1;
			ft_enemy_patrol(game, i, k);
			return ;
		}
	}	
	else if (game->data.enemy_loc[i][2] == 1)
	{
		if (game->map.matrix[game->data.enemy_loc[i][0]/64][game->data.enemy_loc[i][1]/64 - 1] == '0'
			 || game->map.matrix[game->data.enemy_loc[i][0]/64][game->data.enemy_loc[i][1]/64 - 1] == 'P'
			 || (game->map.matrix[game->data.enemy_loc[i][0]/64][game->data.enemy_loc[i][1]/64 - 1] == '1'
				 && game->data.enemy_loc[i][1] % 64 != 0))
			game->data.enemy_loc[i][1] -= 16;
		else
		{
			game->data.enemy_loc[i][2] = 0;
			ft_enemy_patrol(game, i, k);
			return ;
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->tex.enemy[k], game->data.enemy_loc[i][1], game->data.enemy_loc[i][0]);
	if (k == 3)
	{
		if (game->map.matrix[game->data.enemy_loc[i][0]/64][game->data.enemy_loc[i][1]/64] == 'P')
			exit(0);
		game->map.matrix[game->data.enemy_loc[i][0]/64][game->data.enemy_loc[i][1]/64] = 'X';
		if (game->data.enemy_loc[i][2] == 0 && game->map.matrix[game->data.enemy_loc[i][0]/64][game->data.enemy_loc[i][1]/64 - 1] == 'X')
		{
			game->map.matrix[game->data.enemy_loc[i][0]/64][game->data.enemy_loc[i][1]/64 - 1] = '0';
		}
		else if (game->data.enemy_loc[i][2] == 1 && game->map.matrix[game->data.enemy_loc[i][0]/64][game->data.enemy_loc[i][1]/64 + 1])
		{
			game->map.matrix[game->data.enemy_loc[i][0]/64][game->data.enemy_loc[i][1]/64 + 1] = '0';
		}
	}
}

void ft_step_text(t_game *game)
{
	char *temp;

	temp = ft_itoa(game->p.steps_taken);
	game->step_text = ft_strjoin("Steps taken: ", temp);
	free(temp);
	mlx_string_put(game->mlx, game->win, 96, 96, 0, game->step_text);
	free(game->step_text);
}

int ft_render(t_game *game)
{
	int i;
	int j;
	int enemy;
	static int k = 0;

	enemy = 0;
	i = 0;
	mlx_clear_window(game->mlx, game->win);
	while (i < game->map.height)
	{
		j=0;
		while (j < game->map.width)
		{
			if (game->map.matrix[i][j] != '1')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.wallpaper, j*64, i*64);	
			if (game->map.matrix[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.wall, j*64, i*64);	
			else if (game->map.matrix[i][j] == 'P' && game->p.move == 0)
				ft_player_idle(game);
			else if (game->map.matrix[i][j] == 'P')
				ft_player_move(game);
			else if (game->map.matrix[i][j] == 'H')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.collectible[0][k], j*64, i*64);
			else if (game->map.matrix[i][j] == 'J')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.collectible[1][k], j*64, i*64);
			else if (game->map.matrix[i][j] == 'K')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.collectible[2][k], j*64, i*64);
			else if (game->map.matrix[i][j] == 'L')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.collectible[3][k], j*64, i*64);
			else if (game->map.matrix[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.exit, j*64, i*64);
			else if (game->map.matrix[i][j] == 'X')
			{
				if (game->data.enemy_loc[enemy][2] == 0 && game->map.matrix[i][j + 1] == '0')
					mlx_put_image_to_window(game->mlx, game->win, game->tex.wallpaper, (++j)*64, i*64);	
				ft_enemy_patrol(game, enemy, k);
				enemy++;
			}
			j++;
		}
		i++;
	}
	ft_step_text(game);
	usleep(30000);
	k++;
	if (k % 4 == 0)
		k = 0;
	return 0;
}

int main(int ac, char **av)
{
	if (ac > 2)
	{
		ft_printf("only 2 arguments!");
		return 0;
	}
	t_game game;
	game.p.steps_taken = 0;
	game.p.move = 0;
	game.p.facing = 1;
	game.p.facing_tmp = 1;
	game.mlx = mlx_init();
	game.map.ber = "./Maps/mapp.ber";
	//ft_strjoin("Maps/", av[1]);
	ft_countmap(&game);
	game.map.matrix = ft_readmap(&game);
	game.map.matrix_clone = ft_readmap(&game);
	ft_findplayer(&game);	
	ft_is_map_valid(&game, game.p.y/64, game.p.x/64);
	if (!ft_is_map_valid2(&game, 0, 0) && !ft_map_name_check(game.map.ber))
	{
		ft_printf("Map is invalid");
		exit(1);
	}
	ft_check_anime_girls(&game);
	ft_check_data(&game);
	ft_gettextures(&game);
	game.win = mlx_new_window(game.mlx, game.map.width*64, game.map.height*64, "so_long");
	ft_render(&game);
	mlx_hook(game.win, 17, 0, &ft_exitmap, &game);
	mlx_hook(game.win, 2, (1L<<0), &ft_buttonrender, &game);
	mlx_loop_hook(game.mlx, &ft_looprender, &game);
	mlx_loop(game.mlx);
}
