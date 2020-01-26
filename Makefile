NAME = fdf
CC = gcc
all: hello
#hello: gcc -Wall -Wextra -Werror -lmlx -lXext -lX11 -L minilibx/ -I minilibx/ main.c -o fdf

hello: main.c 
		 clang -Wall -Wextra -Werror -I./libft -L./libft -lft -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -lm -o fdf main.c control.c 
clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all