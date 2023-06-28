NAME = ft_printf.a

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror

SRCS = \
		ft_printf.c\
		ft_printf_text.c\
		ft_printf_num.c

OBJS = \
		ft_printf.o\
		ft_printf_text.o\
		ft_printf_num.o

all: $(NAME)

$(NAME):
	$(CC) $(CC_FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
