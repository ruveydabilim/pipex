NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c

OBJS = $(SRC:.c=.o)

BNSOBJ = $(BNSRC:.c=.o)

libft = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(libft)
	$(CC) $(CFLAGS) $(OBJS) $(libft) -o $(NAME)

$(libft):	
	make -C ./libft


clean:
	$(RM) $(OBJS) $(BNSOBJ)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re bonus