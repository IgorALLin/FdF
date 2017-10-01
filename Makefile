
NAME 		= fdf

SRC 		= main.c get_next_line.c read.c error.c rotate.c utilities.c key_hook.c draw.c bresenham.c color.c center.c check_line.c

OBJ 		= $(SRC:.c=.o)
FRAMEWORK	= -lmlx -framework OpenGL -framework AppKit
LOCAL		= -I minilibX -g -L minilibX
CFLAGS 		= -Wall -Wextra -Werror
LIBFT		= libft/libft.a

all: $(NAME)
	
$(NAME): $(OBJ)
	@make -C libft/
	$(CC) $(FLAG) $(LIBFT) $(LOCAL) $(FRAMEWORK) $(OBJ) -o $(NAME)
clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(NAME) $(OBJ)

re:	
	@make fclean 
	@make all
	@make clean
