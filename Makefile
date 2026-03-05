# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpinho-c <cpinho-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/14 14:25:30 by cpinho-c          #+#    #+#              #
#    Updated: 2026/03/05 22:54:35 by cpinho-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = pipex.c \
	   utils/checks.c \
	   utils/tasks.c
	   
OBJS = $(SRCS:.c=.o)
RM = rm -f
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_GIT = https://github.com/kamipc/42_Libft.git

.SILENT:

all: $(NAME)

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
	echo "Cloning libft..."; \
	git clone $(LIBFT_GIT) $(LIBFT_DIR); \
	fi
	$(MAKE) -C $(LIBFT_DIR)
	echo "Libft compiled successfully!"

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -g -O0 $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	echo "$(NAME) compiled successfuly!"

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS)
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -C $(LIBFT_DIR) clean; fi

fclean: clean
	$(RM) $(NAME)
	@if [ -d "$(LIBFT_DIR)" ]; then $(MAKE) -C $(LIBFT_DIR) fclean; fi

re: fclean all
