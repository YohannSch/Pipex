# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohann <yohann@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/05 12:49:33 by yohann          #+#    #+#              #
#    Updated: 2025/12/01 02:45:35 by yohann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

#Source#####################################

SRC += ft_atoi.c
SRC += ft_bzero.c
SRC += ft_calloc.c
SRC += ft_isalnum.c
SRC += ft_isalpha.c
SRC += ft_isascii.c
SRC += ft_isdigit.c
SRC += ft_isprint.c
SRC += ft_itoa.c
SRC += ft_memchr.c
SRC += ft_memcmp.c
SRC += ft_memcpy.c
SRC += ft_memmove.c
SRC += ft_memset.c
SRC += ft_putchar_fd.c
SRC += ft_putendl_fd.c
SRC += ft_putnbr_fd.c
SRC += ft_putstr_fd.c
SRC += ft_split.c
SRC += ft_strchr.c
SRC += ft_strdup.c
SRC += ft_striteri.c
SRC += ft_strjoin.c
SRC += ft_strlcat.c
SRC += ft_strlcpy.c
SRC += ft_strlen.c
SRC += ft_strmapi.c
SRC += ft_strncmp.c
SRC += ft_strnstr.c
SRC += ft_strrchr.c
SRC += ft_strtrim.c
SRC += ft_substr.c
SRC += ft_tolower.c
SRC += ft_toupper.c
SRC += ft_lstnew.c
SRC += ft_lstadd.c
SRC += ft_lstsearch.c
SRC += ft_lstsize.c
SRC += ft_atoll.c
SRC += ft_strcpy.c

#Includes###################################

INCLUDES_LIBFT = libft.h

#Compilation################################

CC = gcc

CFLAGS := -Werror -Wextra -Wall -g3

#Rules######################################

OBJ := $(SRC:.c=.o)

all: $(NAME)

%.o: %.c $(INCLUDES_LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re