# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 17:00:10 by aayoub            #+#    #+#              #
#    Updated: 2025/01/15 16:56:36 by aboumall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEAD = main.h

CC = cc

CFLAGS = -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
SRC = 	$(SRC_DIR)/sort_small.c $(SRC_DIR)/stack_check.c $(SRC_DIR)/stack_push.c \
		$(SRC_DIR)/stack_rotate.c $(SRC_DIR)/stack_swap.c $(SRC_DIR)/stack_utils.c \
		$(SRC_DIR)/stack.c $(SRC_DIR)/sort.c $(SRC_DIR)/tester.c $(SRC_DIR)/sort_large.c \
		$(SRC_DIR)/target.c $(SRC_DIR)/cheapest_move.c

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEAD) $(SRC) Makefile
	$(CC) main.c $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEAD) Makefile | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re