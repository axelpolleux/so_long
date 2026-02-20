#________________BASICS________________
CC					:= cc
CFLAGS				:= -Wall -Werror -Wextra -g

UNAME_S				:= $(shell uname -s)

INCLUDES_DIR		:= -Iincludes/
NAME					:= so_long

LIBFT_DIR			:= includes/libft/
LIBFT				:= $(LIBFT_DIR)libft.a

GNL_DIR				:= includes/get_next_line/
GNL_SRCS			:=	$(GNL_DIR)get_next_line.c \
									$(GNL_DIR)get_next_line_utils.c

MLX_DIR				:= includes/MacroLibX/
MLX_INCLUDES		:= -I$(MLX_DIR)includes
MLX_LIB_NAME		:= libmlx.so
SDL2_LIBS			?= -lSDL2
RPATH_FLAGS			:= -Wl,-rpath,'$$ORIGIN/$(MLX_DIR)'
MLX_TOOLCHAIN		?= gcc

ifeq ($(UNAME_S),Darwin)
	MLX_LIB_NAME	:= libmlx.dylib
	RPATH_FLAGS		:= -Wl,-rpath,@loader_path/$(MLX_DIR)
	MLX_TOOLCHAIN	?= clang
endif

MLX					:= $(MLX_DIR)$(MLX_LIB_NAME)
INCLUDES			:= $(INCLUDES_DIR) $(MLX_INCLUDES)

#________________FILES________________

SRCS					:=	$(GNL_SRCS) \
									srcs/main.c \
									srcs/parser/parser.c \
									srcs/parser/flood_fill.c \
									srcs/utils/str_manager.c \
									srcs/utils/map_manager.c \
									srcs/utils/memory_map.c	\
									srcs/game/init.c

OBJS					:= $(SRCS:.c=.o)

#________________RULES________________
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@printf "\n✔ BUILD COMPLETE\n"
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) $(MLX) $(SDL2_LIBS) $(RPATH_FLAGS) -o $(NAME)


#________________LIBS________________
$(LIBFT):
	@echo "Libft [COMPILING]"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	@echo "MacroLibX [COMPILING]"
	@$(MAKE) -C $(MLX_DIR) TOOLCHAIN=$(MLX_TOOLCHAIN) --no-print-directory

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "[CLEAN]"
	@rm -f $(OBJS)
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory

fclean: clean
	@echo "[FCLEAN]"
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) fclean --no-print-directory
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
