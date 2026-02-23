#________________BASICS________________
CC					:= cc
CFLAGS				:= -Wall -Werror -Wextra -g

INCLUDES_DIR		:= -Iincludes/ -Iincludes/MacroLibX/includes/
NAME					:= so_long

LIBFT_DIR			:= includes/libft/
LIBFT				:= $(LIBFT_DIR)libft.a

GNL_DIR				:= includes/get_next_line/
GNL_SRCS			:=	$(GNL_DIR)get_next_line.c \
						$(GNL_DIR)get_next_line_utils.c

MLX_DIR				:= includes/MacroLibX/
MLX					:= $(MLX_DIR)libmlx.so

INCLUDES			:= $(INCLUDES_DIR)

#________________FILES________________

SRCS					:=	$(GNL_SRCS) \
									srcs/main.c 				\
									srcs/parser/parser.c 		\
									srcs/parser/flood_fill.c 	\
									srcs/utils/str_manager.c 	\
									srcs/utils/map_manager.c 	\
									srcs/utils/memory_map.c		\
									srcs/game/init.c			\
									srcs/game/window.c			\
									srcs/game/drawing.c			\
									srcs/game/events.c			\
									srcs/game/hooks.c
									

OBJS					:= $(SRCS:.c=.o)

#________________RULES________________
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@printf "\n✔ BUILD COMPLETE\n"
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) $(MLX) -lSDL2 -o $(NAME)


#________________LIBS________________
$(LIBFT):
	@echo "Libft [COMPILING]"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "MacroLibX [COMPILING]"
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "[CLEAN]"
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@echo "[FCLEAN]"
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
