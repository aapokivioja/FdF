# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: akivioja <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/03 14:50:12 by akivioja      #+#    #+#                  #
#    Updated: 2022/11/16 16:54:44 by akivioja      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := gcc
CFLAGS := -Wall -Wextra -Werror 
RM := rm -f

CFILES := ft_atoi.c ft_isdigit.c ft_memset.c ft_strncmp.c \
		ft_bzero.c ft_isprint.c ft_strchr.c ft_strnstr.c \
		ft_calloc.c ft_memchr.c ft_strdup.c ft_strrchr.c \
		ft_isalnum.c ft_memcmp.c ft_strlcat.c ft_tolower.c \
		ft_isalpha.c ft_memcpy.c ft_strlcpy.c ft_toupper.c \
		ft_isascii.c ft_memmove.c ft_strlen.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJECTS := $(CFILES:.c=.o)

all: $(NAME)

$(NAME):	$(OBJECTS)
	$(CC) $(CFLAGS) -c $(CFILES)
	ar rcs $(NAME) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJECTS)


re: fclean all

.PHONY: all
