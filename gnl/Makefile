NAME = gnl.a

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

SRCS = \
		get_next_line.c\
		get_next_line_utils.c

OBJS = \
		get_next_line.o\
		get_next_line_utils.o

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all