#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libraries/lib/libft/libft.h"
# include "../Libraries/lib/printf/ft_printf_bonus.h"
# include "../Libraries/lib/gnl/get_next_line.h"
# include "../Libraries/minilibx/mlx.h"
# include <fcntl.h>

typedef struct s_map
{
	char *ber;
	char **matrix;
	char **matrix_clone;
	int width;
	int height;
}	t_map;

typedef struct s_texture
{
	void *mc_idle_r[8];
	void *mc_idle_l[8];
	void *mc_move_r[8];
	void *mc_move_l[8];
	void *mc_jump_r[8];
	void *mc_jump_l[8];
	void *collectible[4][4];
	void *enemy[4];
	void *wall;
	void *wallpaper;
	void *exit;
}	t_texture;

typedef struct s_player
{
	int x;
	int y;
	int facing;
	int facing_tmp;
	int move;
	int steps_taken;
	int collacted;
}	t_player;

typedef struct s_data
{
	int C;
	int E;
	int X;
	int P;
	int finish;
	int **enemy_loc;
}	t_data;

typedef struct s_game
{
	t_map map;
	t_texture tex;
	t_player p;
	t_data data;
	void *mlx;
	void *win;
	int tmp_collectible;
	int tmp_exit;
	char *step_text;
}	t_game;

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_J 38
# define KEY_ESC 53
# define IDLE_R0 "./Textures/mc_idle/mc_idle_r0.xpm"
# define IDLE_R1 "./Textures/mc_idle/mc_idle_r1.xpm"
# define IDLE_R2 "./Textures/mc_idle/mc_idle_r2.xpm"
# define IDLE_R3 "./Textures/mc_idle/mc_idle_r3.xpm"
# define IDLE_R4 "./Textures/mc_idle/mc_idle_r4.xpm"
# define IDLE_R5 "./Textures/mc_idle/mc_idle_r5.xpm"
# define IDLE_R6 "./Textures/mc_idle/mc_idle_r6.xpm"
# define IDLE_R7 "./Textures/mc_idle/mc_idle_r7.xpm"
# define IDLE_L0 "./Textures/mc_idle/mc_idle_l0.xpm"
# define IDLE_L1 "./Textures/mc_idle/mc_idle_l1.xpm"
# define IDLE_L2 "./Textures/mc_idle/mc_idle_l2.xpm"
# define IDLE_L3 "./Textures/mc_idle/mc_idle_l3.xpm"
# define IDLE_L4 "./Textures/mc_idle/mc_idle_l4.xpm"
# define IDLE_L5 "./Textures/mc_idle/mc_idle_l5.xpm"
# define IDLE_L6 "./Textures/mc_idle/mc_idle_l6.xpm"
# define IDLE_L7 "./Textures/mc_idle/mc_idle_l7.xpm"
# define MOVE_R0 "./Textures/mc_move_right/mc_move_right0.xpm"
# define MOVE_R1 "./Textures/mc_move_right/mc_move_right1.xpm"
# define MOVE_R2 "./Textures/mc_move_right/mc_move_right2.xpm"
# define MOVE_R3 "./Textures/mc_move_right/mc_move_right3.xpm"
# define MOVE_R4 "./Textures/mc_move_right/mc_move_right4.xpm"
# define MOVE_R5 "./Textures/mc_move_right/mc_move_right5.xpm"
# define MOVE_R6 "./Textures/mc_move_right/mc_move_right6.xpm"
# define MOVE_R7 "./Textures/mc_move_right/mc_move_right7.xpm"
# define MOVE_L0 "./Textures/mc_move_left/mc_move_left0.xpm"
# define MOVE_L1 "./Textures/mc_move_left/mc_move_left1.xpm"
# define MOVE_L2 "./Textures/mc_move_left/mc_move_left2.xpm"
# define MOVE_L3 "./Textures/mc_move_left/mc_move_left3.xpm"
# define MOVE_L4 "./Textures/mc_move_left/mc_move_left4.xpm"
# define MOVE_L5 "./Textures/mc_move_left/mc_move_left5.xpm"
# define MOVE_L6 "./Textures/mc_move_left/mc_move_left6.xpm"
# define MOVE_L7 "./Textures/mc_move_left/mc_move_left7.xpm"
# define COLLECTIBLE1_0 "./Textures/collectible/megumin0.xpm"
# define COLLECTIBLE1_1 "./Textures/collectible/megumin1.xpm"
# define COLLECTIBLE1_2 "./Textures/collectible/megumin2.xpm"
# define COLLECTIBLE1_3 "./Textures/collectible/megumin3.xpm"
# define COLLECTIBLE2_0 "./Textures/collectible/ram0.xpm"
# define COLLECTIBLE2_1 "./Textures/collectible/ram1.xpm"
# define COLLECTIBLE2_2 "./Textures/collectible/ram2.xpm"
# define COLLECTIBLE2_3 "./Textures/collectible/ram3.xpm"
# define COLLECTIBLE3_0 "./Textures/collectible/rem0.xpm"
# define COLLECTIBLE3_1 "./Textures/collectible/rem1.xpm"
# define COLLECTIBLE3_2 "./Textures/collectible/rem2.xpm"
# define COLLECTIBLE3_3 "./Textures/collectible/rem3.xpm"
# define COLLECTIBLE4_0 "./Textures/collectible/umaru0.xpm"
# define COLLECTIBLE4_1 "./Textures/collectible/umaru1.xpm"
# define COLLECTIBLE4_2 "./Textures/collectible/umaru2.xpm"
# define COLLECTIBLE4_3 "./Textures/collectible/umaru3.xpm"
# define ENEMY0 "./Textures/enemy/enemy0.xpm"
# define ENEMY1 "./Textures/enemy/enemy1.xpm"
# define ENEMY2 "./Textures/enemy/enemy2.xpm"
# define ENEMY3 "./Textures/enemy/enemy3.xpm"
# define EXIT "./Textures/exit.xpm"
# define WALL "./Textures/wall.xpm"
# define WALLPAPER "./Textures/wallpaper.xpm"

int ft_buttonrender(int keycode, t_game *game);
void ft_gettextures(t_game *game);
void ft_player_move(t_game *game);
int ft_looprender(t_game *game);
void ft_player_idle(t_game *game);
int ft_render(t_game *game);
void ft_countmap(t_game *game);
char **ft_readmap(t_game *game);
void ft_findplayer(t_game *game);
void ft_check_anime_girls(t_game *game);
int ft_exitmap(t_game *game);
int	ft_map_name_check(char *path);
int	ft_is_map_valid2(t_game *game, int i, int j);
void ft_is_map_valid(t_game *game, int x, int y);
void ft_did_finish(t_game *game, int i, int j);
#endif

