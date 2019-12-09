NAME = fdf
CC = gcc
all: hello
#hello: gcc -Wall -Wextra -Werror -lmlx -lXext -lX11 -L minilibx/ -I minilibx/ main.c -o fdf

hello: main.c 
		 clang main.c  -Wall -Wextra -Werror -lmlx -lXext -lm -lX11 -L minilibx/ -I minilibx/ -o fdf
clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all