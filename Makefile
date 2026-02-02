CC := cc
CFLAGS := -Wall -Werror -Wextra -g

INCLUDES_DIR = includes/
NAME := so_long

#________________RULES________________

all: $(NAME)

$(NAME):

$(LIBFT):

$(GNL):

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "[CLEAN]"
	@rm -f $(OBJS)

fclean: clean
	@echo "[FCLEAN]"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
