#________________BASICS________________
CC := cc
CFLAGS := -Wall -Werror -Wextra -g

INCLUDES_DIR = -Iincludes
NAME := so_long

LIBFT := libft.a

#________________FILES________________
SRCS := srcs/main.c \
				srcs/parser/parser.c

OBJS := $(SRCS:.c=.o)

#________________RULES________________
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf "\n✔ BUILD COMPLETE\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(INCLUDES_DIR) -o $(NAME)


#________________LIBS________________
$(LIBFT):
	@echo "Libft [COMPILING]"
	@$(MAKE) -C $(INCLUDES_DIR)/libft --no-print-directory

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES_DIR) -c $< -o $@

clean:
	@echo "[CLEAN]"
	@rm -f $(OBJS)

fclean: clean
	@echo "[FCLEAN]"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
