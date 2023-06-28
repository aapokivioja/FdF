NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC_PATH    = src/
OBJ_PATH    = obj/

LIBFT = libft/libft.a
PRINTF = ft_printf/ft_printf.a
GNL = gnl/gnl.a

LIBS = -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit

SRC = \
	fdf.c \
	parse.c \
	draw.c \
	main.c

SRCS        = $(addprefix $(SRC_PATH), $(SRC))

OBJ         = $(SRC:.c=.o)
OBJS        = $(addprefix $(OBJ_PATH), $(OBJ))

INC         = -I ./include/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(MAKE) all -C libft
	$(MAKE) all -C ft_printf
	$(MAKE) all -C gnl
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF) $(GNL) $(LIBS)

clean:
	rm -rf $(OBJ_PATH)
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf
	$(MAKE) clean -C gnl

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf
	$(MAKE) fclean -C gnl

re: fclean all

.PHONY: all clean fclean re
