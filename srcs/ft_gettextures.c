#include "./so_long.h"

void ft_gettextures(t_game *game)
{
	int x;
	int y;

	x = 64;
	y = 64;
	game->tex.wall = mlx_xpm_file_to_image(game->mlx, WALL, &x, &y);
	game->tex.wallpaper = mlx_xpm_file_to_image(game->mlx, WALLPAPER, &x, &y);
	game->tex.exit = mlx_xpm_file_to_image(game->mlx, EXIT, &x, &y);
	game->tex.mc_idle_r[0] = mlx_xpm_file_to_image(game->mlx, IDLE_R0, &x, &y);
	game->tex.mc_idle_r[1] = mlx_xpm_file_to_image(game->mlx, IDLE_R1, &x, &y);
	game->tex.mc_idle_r[2] = mlx_xpm_file_to_image(game->mlx, IDLE_R2, &x, &y);
	game->tex.mc_idle_r[3] = mlx_xpm_file_to_image(game->mlx, IDLE_R3, &x, &y);
	game->tex.mc_idle_r[4] = mlx_xpm_file_to_image(game->mlx, IDLE_R4, &x, &y);
	game->tex.mc_idle_r[5] = mlx_xpm_file_to_image(game->mlx, IDLE_R5, &x, &y);
	game->tex.mc_idle_r[6] = mlx_xpm_file_to_image(game->mlx, IDLE_R6, &x, &y);
	game->tex.mc_idle_r[7] = mlx_xpm_file_to_image(game->mlx, IDLE_R7, &x, &y);
	game->tex.mc_idle_l[0] = mlx_xpm_file_to_image(game->mlx, IDLE_L0, &x, &y);
	game->tex.mc_idle_l[1] = mlx_xpm_file_to_image(game->mlx, IDLE_L1, &x, &y);
	game->tex.mc_idle_l[2] = mlx_xpm_file_to_image(game->mlx, IDLE_L2, &x, &y);
	game->tex.mc_idle_l[3] = mlx_xpm_file_to_image(game->mlx, IDLE_L3, &x, &y);
	game->tex.mc_idle_l[4] = mlx_xpm_file_to_image(game->mlx, IDLE_L4, &x, &y);
	game->tex.mc_idle_l[5] = mlx_xpm_file_to_image(game->mlx, IDLE_L5, &x, &y);
	game->tex.mc_idle_l[6] = mlx_xpm_file_to_image(game->mlx, IDLE_L6, &x, &y);
	game->tex.mc_idle_l[7] = mlx_xpm_file_to_image(game->mlx, IDLE_L7, &x, &y);
	game->tex.mc_move_r[0] = mlx_xpm_file_to_image(game->mlx, MOVE_R0, &x, &y);
	game->tex.mc_move_r[1] = mlx_xpm_file_to_image(game->mlx, MOVE_R1, &x, &y);
	game->tex.mc_move_r[2] = mlx_xpm_file_to_image(game->mlx, MOVE_R2, &x, &y);
	game->tex.mc_move_r[3] = mlx_xpm_file_to_image(game->mlx, MOVE_R3, &x, &y);
	game->tex.mc_move_r[4] = mlx_xpm_file_to_image(game->mlx, MOVE_R4, &x, &y);
	game->tex.mc_move_r[5] = mlx_xpm_file_to_image(game->mlx, MOVE_R5, &x, &y);
	game->tex.mc_move_r[6] = mlx_xpm_file_to_image(game->mlx, MOVE_R6, &x, &y);
	game->tex.mc_move_r[7] = mlx_xpm_file_to_image(game->mlx, MOVE_R7, &x, &y);
	game->tex.mc_move_l[0] = mlx_xpm_file_to_image(game->mlx, MOVE_L0, &x, &y);
	game->tex.mc_move_l[1] = mlx_xpm_file_to_image(game->mlx, MOVE_L1, &x, &y);
	game->tex.mc_move_l[2] = mlx_xpm_file_to_image(game->mlx, MOVE_L2, &x, &y);
	game->tex.mc_move_l[3] = mlx_xpm_file_to_image(game->mlx, MOVE_L3, &x, &y);
	game->tex.mc_move_l[4] = mlx_xpm_file_to_image(game->mlx, MOVE_L4, &x, &y);
	game->tex.mc_move_l[5] = mlx_xpm_file_to_image(game->mlx, MOVE_L5, &x, &y);
	game->tex.mc_move_l[6] = mlx_xpm_file_to_image(game->mlx, MOVE_L6, &x, &y);
	game->tex.mc_move_l[7] = mlx_xpm_file_to_image(game->mlx, MOVE_L7, &x, &y);
	game->tex.collectible[0][0] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE1_0, &x, &y);
	game->tex.collectible[0][1] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE1_1, &x, &y);
	game->tex.collectible[0][2] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE1_2, &x, &y);
	game->tex.collectible[0][3] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE1_3, &x, &y);
	game->tex.collectible[1][0] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE2_0, &x, &y);
	game->tex.collectible[1][1] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE2_1, &x, &y);
	game->tex.collectible[1][2] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE2_2, &x, &y);
	game->tex.collectible[1][3] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE2_3, &x, &y);
	game->tex.collectible[2][0] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE3_0, &x, &y);
	game->tex.collectible[2][1] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE3_1, &x, &y);
	game->tex.collectible[2][2] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE3_2, &x, &y);
	game->tex.collectible[2][3] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE3_3, &x, &y);
	game->tex.collectible[3][0] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE4_0, &x, &y);
	game->tex.collectible[3][1] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE4_1, &x, &y);
	game->tex.collectible[3][2] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE4_2, &x, &y);
	game->tex.collectible[3][3] = mlx_xpm_file_to_image(game->mlx, COLLECTIBLE4_3, &x, &y);
	game->tex.enemy[0] = mlx_xpm_file_to_image(game->mlx, ENEMY0, &x, &y);
	game->tex.enemy[1] = mlx_xpm_file_to_image(game->mlx, ENEMY1, &x, &y);
	game->tex.enemy[2] = mlx_xpm_file_to_image(game->mlx, ENEMY2, &x, &y);
	game->tex.enemy[3] = mlx_xpm_file_to_image(game->mlx, ENEMY3, &x, &y);

}



