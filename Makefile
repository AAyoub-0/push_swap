# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 17:00:10 by aayoub            #+#    #+#              #
#    Updated: 2025/01/29 16:15:27 by aboumall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap
BONUS_NAME	=	checker

HEAD 		= 	push_swap.h

CC 			= 	cc

CFLAGS 		= 	-Wall -Wextra -Werror

LIBFT_DIR 	= 	./libft
SRC_DIR 	= 	src

MAND_MAIN	=	src/push_swap.c
BONUS_MAIN	=	src/checker_bonus.c
LIBFT_A 	= 	libft.a
SRC_SRC 	= 	sort_small.c stack_push.c \
				stack_rotate.c stack_swap.c stack_utils.c 	\
				stack.c sort.c sort_large.c target.c cheapest_move.c

LIBFT 		= $(addprefix $(LIBFT_DIR)/, $(LIBFT_A))
SRC   		= $(addprefix $(SRC_DIR)/, $(SRC_SRC))

OBJ_DIR 	= obj
OBJ 		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(HEAD) $(SRC) Makefile $(MAND_MAIN)
	$(CC) $(MAND_MAIN) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

bonus: $(LIBFT) $(OBJ) $(HEAD) $(SRC) Makefile $(BONUS_MAIN)
	$(CC) $(BONUS_MAIN) $(CFLAGS) -o $(BONUS_NAME) $(OBJ) $(LIBFT)
	
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
	rm -f $(BONUS_NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus