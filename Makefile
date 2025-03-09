NAME	= so_long

CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBMLX	:= ./MLX42

HEADERS	= -I $(LIBMLX)/include

LIBS := -lglfw -L"/Users/ychedmi/.brew/opt/glfw/lib" $(LIBMLX)/build/libmlx42.a -pthread -ldl -lm -framework Cocoa -framework OpenGL -framework IOKit

SRCS	= so_long.c	./get_next_line/get_next_line.c		./get_next_line/get_next_line_utils.c \
		./tools/ft_lstadd_back.c	./tools/ft_lstnew.c\
		./tools/ft_lstlast.c 	./tools/ft_lstadd_front.c		./tools/ft_lstsize.c \
		walls_checker.c	validmap.c	flood_fill.c 	./game/init_game.c\

OBJS	= ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c	so_long.h get_next_line/get_next_line.h
	${CC} ${CFLAGS} -o $@ -c $< ${HEADERS}

${NAME}: ${OBJS}
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

build:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all