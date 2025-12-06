# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yscheupl <yscheupl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/06 19:34:10 by yscheupl          #+#    #+#              #
#    Updated: 2025/12/06 20:06:57 by yscheupl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC      := cc
CFLAGS  := -Wall -Wextra -Werror -g3
RM      := rm -rf

NAME    := pipex

SRCS    := pipex.c execution/exec.c parsing/parsing.c parsing/parsing_utils.c

OBJS    := $(SRCS:.c=.o)

LIBFT_A := libft/libft.a
LIBFT_DIR := libft

all: $(LIBFT_A) $(NAME)
	
$(LIBFT_A) : $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_A) -o $(NAME)

clean:
	make -C libft/ fclean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re