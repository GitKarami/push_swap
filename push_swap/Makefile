# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kchahmi <kchahmi@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2024/02/12 17:32:47 by kchahmi       #+#    #+#                  #
#    Updated: 2024/03/25 14:49:43 by kchahmi       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
RM = rm -rf

NAME = push_swap

SRCS =	src/main.c src/instructions.c src/instructions_a.c src/instructions_b.c \
		src/stack.c utils/parser.c utils/helper.c src/instructions_ab.c src/sort.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
re: fclean all