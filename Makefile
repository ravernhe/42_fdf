# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/31 20:48:14 by ravernhe          #+#    #+#              #
#    Updated: 2019/05/31 20:49:06 by ravernhe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= fdf
SRC 	= srcs/main.c\
				srcs/parse.c\
				srcs/check_error.c\
				srcs/algo.c\
				srcs/ft_center.c\
				srcs/deal_key.c
FLAGS 	= -Werror -Wall -Wextra
FRAMEWORK	= -framework OpenGL -framework AppKit
CC 		= gcc

OBJ = $(SRC:.c=.o)
	CL=\x1b[35m
	GREEN=\033[1;32m
	RED=\033[1;31m
	CL2=\x1b[36m
	NC=\033[0m

all: $(NAME)

%.o: %.c
		@$(CC) -c $< -o $@ $(FLAGS)

$(NAME): $(OBJ)
	@make -C ./libft
	@$(CC) $(FLAGS) -I includes/fdf.h -I /usr/local/include $(SRC) -o $(NAME)\
		-I libft/ -L libft/ -lft -L /usr/local/lib/ -lmlx $(FRAMEWORK)
	@echo "$(GREEN)[✓]$(NC)$(CL) executable $(NAME) built$(NC)"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)
	@echo "$(RED)[-]$(NC)$(CL2) Objects of $(NAME) cleaned$(NC)"

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)
	@echo "$(RED)[-]$(NC)$(CL2) Library $(NAME) cleaned$(NC)"

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
