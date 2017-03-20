# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealbert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/05 17:41:53 by ealbert           #+#    #+#              #
#    Updated: 2017/03/20 16:58:41 by ealbert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = -Wall -Werror -Wextra -I includes/

SRC =	src/main.c		\
		src/hooks.c		\
		src/save.c		\
		src/parser.c	\
		src/raycast.c	\
		src/move.c		\
		src/draw.c

$(NAME) :
	@echo "\033[33;33m===Wolf3D : Beginning compilation...\033[0m"
	@echo "\033[33;33m===Wolf3D : Compiling 'libft'...\033[0m"
	@make -C libft/
	@echo "\033[33;32m===Wolf3D : 'libft' compiled."
	@echo "\033[33;33m===Wolf3D : Compiling 'minilibx'...\033[0m"
	@make -C minilibx_macos/
	@echo "\033[33;32m===Wolf3D : 'minilibx' compiled."
	@echo "\033[33;33m===Wolf3D : Compiling 'Wolf3D'...\033[0m"
	@gcc $(SRC) -o $(NAME) $(FLAGS) libft/libft.a minilibx_macos/libmlx.a \
		-lmlx -framework OpenGL -framework AppKit
	@echo "\033[33;32m===Wolf3D : Compilation done.\033[0m"


all : $(NAME)

clean :
	@make fclean -C libft/
	@make clean -C minilibx_macos/
	@echo "\033[33;32m===Wolf3D : Cleaned.\033[0m"

fclean : clean
	@rm -f wolf3d
	@echo "\033[33;32m===Wolf3D : 'wolf3d' removed."

re : fclean all

.PHONY : all clean fclean re
