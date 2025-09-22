NAME = pipex
B_NAME = pipexbonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c

BNSRC = ./pipex_bonus/pipex_bonus.c ./pipex_bonus/pipex_bonus_utils.c 

OBJS = $(SRC:.c=.o)

BNSOBJ = $(BNSRC:.c=.o)

LIBFT = ./libft/libft.a

GNL = ./get_next_line/get_next_line.c

GNLU = ./get_next_line/get_next_line_utils.c

UTILS = pipex_utils.c

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(UTILS) $(GNL) $(GNLU) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

bonus: $(BNSOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BNSOBJ) $(LIBFT) $(GNL) $(GNLU) -o $(B_NAME)

clean:
	$(RM) $(OBJS) $(BNSOBJ)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME) $(B_NAME)

re: fclean all

.PHONY: all fclean clean re bonus