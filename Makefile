#________________BASICS________________
CC					:= cc
CFLAGS				:= -Wall -Werror -Wextra -g

INCLUDES_DIR		:= -Iincludes/
NAME					:= so_long

LIBFT_DIR			:= includes/libft/
LIBFT				:= $(LIBFT_DIR)libft.a

GNL_DIR				:= includes/get_next_line/
GNL_SRCS			:=	$(GNL_DIR)get_next_line.c \
									$(GNL_DIR)get_next_line_utils.c

#________________FILES________________

SRCS					:=	$(GNL_SRCS) \
									srcs/main.c \
									srcs/parser/parser.c \
									srcs/utils/str_manager.c \
									srcs/utils/map_manager.c

OBJS					:= $(SRCS:.c=.o)

#________________RULES________________
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf "\n✔ BUILD COMPLETE\n"
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES_DIR) $(LIBFT) -o $(NAME)


#________________LIBS________________
$(LIBFT):
	@echo "Libft [COMPILING]"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES_DIR) -c $< -o $@

clean:
	@echo "[CLEAN]"
	@rm -f $(OBJS)

fclean: clean
	@echo "[FCLEAN]"
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
