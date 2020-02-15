NAME = fdf

SRC = draw.c			draw2.c		main.c	float_maxmod.c\
	  read_file.c        read_file2.c\

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME):
	@make -C ./libft re
	@gcc -g -o $(NAME) -Wall -Wextra -Werror $(SRC) -L ./libft -lft -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

clean:
	@make -C ./libft fclean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C ./libft fclean
	@/bin/rm -f $(NAME)

re: fclean all






