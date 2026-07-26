NAME := minishell
NAME_BONUS := minishell_bonus
CC := cc
CFLAGS := -Wall -Werror -Wextra -g3

SRC := \
src/001_main/

SRC_BONUS := \

OBJ := $(SRC:.c=.o)
OBJ_BONUS := $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -Iinclude $(OBJ) -lreadline -lhistory -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) -Iinclude_bonus $(OBJ_BONUS) -lreadline -lhistory -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus