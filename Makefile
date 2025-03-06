CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

SRC = 	so_long.c	./get_next_line/get_next_line.c		./get_next_line/get_next_line_utils.c \
		./tools/ft_lstadd_back.c	./tools/ft_lstnew.c\
		./tools/ft_lstlast.c 	./tools/ft_lstadd_front.c		./tools/ft_lstsize.c \
		walls_checker.c	validmap.c	flood_fill.c\
		

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c ./get_next_line/get_next_line.h so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all