#________________BASICS________________
CC				:= cc
CFLAGS			:= -Wall -Werror -Wextra -g

INCLUDES_DIR	:= -Iincludes/
NAME			:= so_long

LIBFT_DIR		:= includes/libft/
LIBFT			:= $(LIBFT_DIR)libft.a

#________________FILES________________
SRCS			:=	srcs/main.c \
					srcs/parser/parser.c

OBJS			:= $(SRCS:.c=.o)

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
