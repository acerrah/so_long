#include "so_long.h"

int ft_buttonrender(int keycode, t_game *game)
{
	if (keycode == KEY_W && game->map.matrix[game->p.x/64 - 1][game->p.y/64] != '1' && game->p.move == 0 && 
			((game->map.matrix[game->p.x/64 - 1][game->p.y/64] != 'E') || game->data.C == 0))
	{
		game->p.move = 64;
		game->p.facing_tmp = game->p.facing;
		game->p.facing = 3;
		game->p.steps_taken++;
		ft_render(game);
	}
	else if (keycode == KEY_A && game->map.matrix[game->p.x/64][game->p.y/64 - 1] != '1' && game->p.move == 0 &&
			((game->map.matrix[game->p.x/64][game->p.y/64 - 1] != 'E') || game->data.C == 0))
	{
		game->p.move = 64;
		game->p.facing = 0;
		game->p.steps_taken++;
		ft_render(game);
	}
	else if (keycode == KEY_S && game->map.matrix[game->p.x/64 + 1][game->p.y/64] != '1' && game->p.move == 0 &&
			((game->map.matrix[game->p.x/64 + 1][game->p.y/64] != 'E') || game->data.C == 0))
	{
		game->p.move = 64;
		game->p.facing_tmp = game->p.facing;
		game->p.facing = 2;
		ft_did_finish(game, 1,0);
		game->map.matrix[game->p.x/64 + 1][game->p.y/64] = 'P';
		game->map.matrix[game->p.x/64][game->p.y/64] = '0';
		game->p.steps_taken++;
		ft_render(game);
	}
	else if (keycode == KEY_D && game->map.matrix[game->p.x/64][game->p.y/64 + 1] != '1' && game->p.move == 0 &&
			((game->map.matrix[game->p.x/64][game->p.y/64 + 1] != 'E') || game->data.C == 0))
	{
		game->p.move = 64;
		game->p.facing = 1;
		ft_did_finish(game, 0,1);
		game->map.matrix[game->p.x/64][game->p.y/64 + 1] = 'P';
		game->map.matrix[game->p.x/64][game->p.y/64] = '0';
		game->p.steps_taken++;
		ft_render(game);
	}	
	if (keycode == KEY_ESC)
		ft_exitmap(game);
	return (0);
}
