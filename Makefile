SRC_FILES		=	main.c \
					actions/events.c \
					actions/key_mouse_events.c \
					actions/movements.c \
					drawing/animate.c \
					drawing/draw.c \
					drawing/minimap.c \
					drawing/minimap2.c \
					free/errors.c \
					free/free.c \
					init/door.c \
					init/get_images.c \
					init/init.c \
					init/map_init.c \
					map_parsing/map_parsing.c \
					map_parsing/utils.c \
					map_parsing/sizing_utils.c \
					map_parsing/get_colour_value.c \
					map_errors/map_errors.c \
					map_errors/is_valid_space.c \
					map_errors/is_valid_wall_utils.c \
					map_errors/utils.c \
					other/door_funcs.c \
					other/utility_funcs.c \
					raycasting/ray_utils.c \
					raycasting/rays.c


SRC_DIR			=	srcs/

SRCS			=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES		=	$(SRC_FILES:.c=.o)

OBJ_DIR			=	objects/

OBJS			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

INCS			=	-Iincludes/ -Imlx


PLAIN			=	\033[0m
RED				=	\033[3;91m
CYAN			=	\033[36m

CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	cub3D
LIBFT			=	libft.a
LIBFT_DIR		=	srcs/libft/
MLX				=	libmlx.dylib
MLX_DIR			=	mlx/

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_DIR)$(LIBFT) $(MLX)
				@$(CC) $(CFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $@ $^
				@echo "$(RED)cub3d has compiled$(PLAIN)"

$(MLX):
				@echo "$(CYAN)Making MLX Library$(PLAIN)"
				@make -C $(MLX_DIR)
				@cp ./mlx/libmlx.dylib .

$(LIBFT_DIR)$(LIBFT):
				@echo "$(CYAN)Making libft$(PLAIN)"
				@make -C $(LIBFT_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -c $(INCS) -o $@ $<

clean:
				@$(RM) $(OBJ_DIR)
				@make -C $(LIBFT_DIR) fclean
				@make -C ./mlx clean
				@$(RM) libmlx.dylib

fclean:			clean
				@$(RM) $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
