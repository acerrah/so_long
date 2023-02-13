NAME = so_long
CFLAGS = -Wall -Werror -Wextra -I./Libraries/minilibx -g
MFLAGS = -framework Appkit -framework OpenGL -L ./Libraries/minilibx -lmlx
MLX = ./Libraries/minilibx/libmlx.a
LIB = ./Libraries/lib/lib.a
SRCS = srcs/main.c \
	   srcs/window.c \
	   srcs/ft_gettextures.c \
	   srcs/ft_player_move.c \
	   srcs/ft_buttonrender.c \
	   srcs/is_valid.c

all: ${MLX} ${NAME}

${NAME}: ${SRCS} ${MLX} ${LIB}
	@gcc -g ${MFLAGS} ${SRCS} ${LIB} -o ${NAME}

${MLX}:
	@make -C ./Libraries/minilibx
${LIB}:
	@make -C ./Libraries/lib
clean:
	@rm -rf ${NAME}

re: clean all

.PHONY: clean re
