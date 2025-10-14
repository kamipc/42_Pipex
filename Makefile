# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 14:25:30 by cpinho-c          #+#    #+#              #
#    Updated: 2025/05/14 14:25:35 by cpinho-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = pipex.c utils/checks.c utils/tasks.c
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBFT = libft/libft.a

.SILENT:

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) -g -O0 $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
