NAME = fdf

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./libft

LIBS = -lft -lm 

LIB_DIR = -L./libft

SRCS = main.c ptr.c figure.c rotate.c

MINILIBX = -L/usr/local/lib/ -I/usr/local/include -framework OpenGL -framework AppKit -lmlx

all: $(NAME)

$(NAME): obj libft.a $(SRCS)
	$(CC) $(FLAGS) $(SRCS) $(LIB_DIR) $(INCLUDES) $(MINILIBX)  $(LIBS) -o $(NAME) -g

libft.a :
	make -C libft/

obj :
	mkdir ./obj

clean:
	make -C libft clean
	@/bin/rm -f *.o

fclean: clean
	make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all