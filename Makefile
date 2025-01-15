# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 17:00:10 by aayoub            #+#    #+#              #
#    Updated: 2025/01/15 18:47:43 by aboumall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= push_swap

HEAD 		= main.h

CC 			= cc

CFLAGS 		= -g

LIBFT_DIR 	= ./libft
SRC_DIR 	= src

LIBFT_A 	= libft.a
SRC_SRC 	= sort_small.c stack_check.c stack_push.c 	\
				stack_rotate.c stack_swap.c stack_utils.c 	\
				stack.c sort.c tester.c sort_large.c 		\
				target.c cheapest_move.c

LIBFT 		= $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))
SRC   		= $(addprefix $(SRC_DIR)/, $(SRC_SRC))

OBJ_DIR 	= obj
OBJ 		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

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