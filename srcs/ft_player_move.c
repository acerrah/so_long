#include "so_long.h"

void ft_did_finish(t_game *game, int i, int j)
{
			if (game->map.matrix[game->p.x/64 + i][game->p.y/64 + j] == 'H' || game->map.matrix[game->p.x/64 + i][game->p.y/64 + j] == 'J'
					||game->map.matrix[game->p.x/64 + i][game->p.y/64 + j] == 'K' ||game->map.matrix[game->p.x/64 + i][game->p.y/64 + j] == 'L')
				game->data.C--;	
			if (game->map.matrix[game->p.x/64 + i][game->p.y/64 + j] == 'E' &&  game->data.C == 0)
				game->data.finish = 1;
			if (game->map.matrix[game->p.x/64 + i][game->p.y/64 + j] == 'X')
				game->data.finish = 2;
}

void ft_end(t_game *game)
{
	if (game->data.finish == 1)
	{
		ft_printf("ANİME KIZLARINI BAŞARIYLA KURTARDIN ARTIK YATAKTA UYUYABİLECEKLER TEBRİKLER");
		exit(0);
	}
	else if (game->data.finish == 2)
	{
		ft_printf("ANİME KIZLARI NEREYE GİTTİ!?!?");
		exit(0);
	}
}

void ft_player_move(t_game *game)
{
	static int i = 0;
	if(game->p.facing == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tex.mc_move_l[i], game->p.y, game->p.x);
		game->p.move -= 8;
		game->p.y -= 8;
		i++;
		if (i % 8 == 0)
		{
			ft_printf("%d steps taken.\n",game->p.steps_taken);
			i = 0;
			ft_did_finish(game, 0, 0);
			game->map.matrix[game->p.x/64][game->p.y/64] = 'P';
			game->map.matrix[game->p.x/64][game->p.y/64 + 1] = '0';
			ft_end(game);
		}
	}
	else if(game->p.facing == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tex.mc_move_r[i], game->p.y, game->p.x);
		game->p.move -= 8;
		game->p.y += 8;
		i++;
		if (i % 8 == 0)
		{
			ft_printf("%d steps taken.\n",game->p.steps_taken);
			i = 0;
			ft_end(game);
		}
	}
	else if(game->p.facing == 2)
	{
		if (game->p.facing_tmp == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->tex.mc_move_r[i], game->p.y, game->p.x);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->tex.mc_move_l[i], game->p.y, game->p.x);
		game->p.move -= 8;
		game->p.x += 8;
		i++;
		if (i % 8 == 0)
		{
			ft_printf("%d steps taken.\n",game->p.steps_taken);
			i = 0;
			game->p.facing = game->p.facing_tmp;
			ft_end(game);
		}
	}
	else if(game->p.facing == 3)
	{
		if (game->p.facing_tmp == 1)
			mlx_put_image_to_window(game->mlx, game->win, game->tex.mc_move_r[i], game->p.y, game->p.x);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->tex.mc_move_l[i], game->p.y, game->p.x);
		game->p.move -= 8;
		game->p.x -= 8;
		i++;
		if (i % 8 == 0)
		{
			ft_printf("%d steps taken.\n",game->p.steps_taken);
			i = 0;
			ft_did_finish(game, 0, 0);
			game->map.matrix[game->p.x/64][game->p.y/64] = 'P';
			game->map.matrix[game->p.x/64 + 1][game->p.y/64] = '0';
			game->p.facing = game->p.facing_tmp;
			ft_end(game);
		}
	}
	usleep(10000);
}
