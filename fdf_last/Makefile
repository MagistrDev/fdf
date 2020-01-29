NAME = fdf

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./libft

LIBS = -lft -lm 

LIB_DIR = -L./libft

SRCS = main.c ptr.c figure.c rotate.c

MINILIBX = -L/usr/local/lib/ -I/usr/local/include -framework OpenGL -framework AppKit -lmlx

all: $(NAME)

$(NAME): $(SRCS:.c=.o) obj
	make -C libft/
	$(CC) $(FLAGS) $(SRCS:.c=.o) $(LIB_DIR) $(INCLUDES) $(MINILIBX)  $(LIBS) -o $(NAME)

%.o : %.c
	$(CC) -c $(FLAGS) $< $(INCLUDES) -o $@
libft.a :
	make -C libft/

clean:
	make -C libft clean
	/bin/rm -f $(SRCS:.c=.o)

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all
