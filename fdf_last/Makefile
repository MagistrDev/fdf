NAME = fdf

CC = gcc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I./libft

LIBS = -lft -lm 

LIB_DIR = -L./libft

SRCS = main.c ptr.c figure.c

MINILIBX = -L/usr/local/lib/ -I/usr/local/include -framework OpenGL -framework AppKit -lmlx

all: $(NAME)

$(NAME): obj_dir $(SRCS)
	$(CC) $(FLAGS) $(SRCS) $(LIB_DIR) $(INCLUDES) $(MINILIBX)  $(LIBS) -o $(NAME) -g

obj_dir :
#	mkdir ./obj

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all