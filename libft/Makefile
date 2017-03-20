# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealbert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 17:58:49 by ealbert           #+#    #+#              #
#    Updated: 2016/12/29 23:32:51 by ealbert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

.PHONY: all clean fclean re

NAME = libft.a

COMPIL = gcc -Wall -Wextra -Werror

SRCS =	SOURCES/ft_atoi.c \
		SOURCES/get_next_line.c \
		SOURCES/ft_itoa_base.c \
		SOURCES/ft_isdigit.c \
		SOURCES/ft_memchr.c \
		SOURCES/ft_memset.c \
		SOURCES/ft_putnbr.c \
		SOURCES/ft_strchr.c \
		SOURCES/ft_strdup.c \
		SOURCES/ft_strlcat.c \
		SOURCES/ft_strncmp.c \
		SOURCES/ft_strrchr.c \
		SOURCES/ft_tolower.c \
		SOURCES/ft_bzero.c \
		SOURCES/ft_isprint.c \
		SOURCES/ft_memcmp.c \
		SOURCES/ft_putchar.c \
		SOURCES/ft_putnbr_fd.c \
		SOURCES/ft_strclr.c \
		SOURCES/ft_strequ.c \
		SOURCES/ft_strlen.c \
		SOURCES/ft_strncpy.c \
		SOURCES/ft_strsplit.c \
		SOURCES/ft_toupper.c \
		SOURCES/ft_isalnum.c \
		SOURCES/ft_itoa.c \
		SOURCES/ft_memcpy.c \
		SOURCES/ft_putchar_fd.c \
		SOURCES/ft_putstr.c \
		SOURCES/ft_strcmp.c \
		SOURCES/ft_striter.c \
		SOURCES/ft_strmap.c \
		SOURCES/ft_strnequ.c \
		SOURCES/ft_strstr.c \
		SOURCES/ft_isalpha.c \
		SOURCES/ft_memalloc.c \
		SOURCES/ft_memdel.c \
		SOURCES/ft_putendl.c \
		SOURCES/ft_putstr_fd.c \
		SOURCES/ft_strcpy.c \
		SOURCES/ft_striteri.c \
		SOURCES/ft_strmapi.c \
		SOURCES/ft_strnew.c \
		SOURCES/ft_strsub.c \
		SOURCES/ft_isascii.c \
		SOURCES/ft_memccpy.c \
		SOURCES/ft_memmove.c \
		SOURCES/ft_putendl_fd.c \
		SOURCES/ft_strcat.c \
		SOURCES/ft_strdel.c \
		SOURCES/ft_strjoin.c \
		SOURCES/ft_strncat.c \
		SOURCES/ft_strnstr.c \
		SOURCES/ft_strtrim.c \
		SOURCES/ft_lstadd.c \
		SOURCES/ft_lstdel.c \
		SOURCES/ft_lstdelone.c \
		SOURCES/ft_lstnew.c \
		SOURCES/ft_lstmap.c \
		SOURCES/ft_lstiter.c \

INCLUDES = -I .

OBJ =	ft_atoi.o \
		get_next_line.o \
		ft_itoa_base.o \
		ft_isdigit.o \
		ft_memchr.o \
		ft_memset.o \
		ft_putnbr.o \
		ft_strchr.o \
		ft_strdup.o \
		ft_strlcat.o \
		ft_strncmp.o \
		ft_strrchr.o \
		ft_tolower.o \
		ft_bzero.o \
		ft_isprint.o \
		ft_memcmp.o \
		ft_putchar.o \
		ft_putnbr_fd.o \
		ft_strclr.o \
		ft_strequ.o \
		ft_strlen.o \
		ft_strncpy.o \
		ft_strsplit.o \
		ft_toupper.o \
		ft_isalnum.o \
		ft_itoa.o \
		ft_memcpy.o \
		ft_putchar_fd.o \
		ft_putstr.o \
		ft_strcmp.o \
		ft_striter.o \
		ft_strmap.o \
		ft_strnequ.o \
		ft_strstr.o \
		ft_isalpha.o \
		ft_memalloc.o \
		ft_memdel.o \
		ft_putendl.o \
		ft_putstr_fd.o \
		ft_strcpy.o \
		ft_striteri.o \
		ft_strmapi.o \
		ft_strnew.o \
		ft_strsub.o \
		ft_isascii.o \
		ft_memccpy.o \
		ft_memmove.o \
		ft_putendl_fd.o \
		ft_strcat.o \
		ft_strdel.o \
		ft_strjoin.o \
		ft_strncat.o \
		ft_strnstr.o \
		ft_strtrim.o \
		ft_lstadd.o \
		ft_lstdel.o \
		ft_lstdelone.o \
		ft_lstmap.o \
		ft_lstiter.o \
		ft_lstnew.o \

$(NAME) :
	@echo "\033[33;33m===LIBFT : Compilation...\033[0m"
	@$(CC) -c $(SRCS) $(INCLUDES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@mkdir TMP
	@mv $(OBJ) TMP
	@echo "\033[33;32m===LIBFT : Compilation done. All the object files are in the TMP repository.\033[0m"

all: $(NAME)

clean:
	@rm -rf TMP
	@echo "\033[33;32m===LIBFT : Removed the object files folder successfully.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[33;32m===LIBFT : Your static library has been successfully removed.\033[0m"

re: fclean all
