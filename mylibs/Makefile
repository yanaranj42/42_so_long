# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 14:32:13 by yanaranj          #+#    #+#              #
#    Updated: 2024/05/08 18:49:24 by yanaranj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS#
GREEN=\033[1;32m
RED=\033[1;31m
BLUE=\033[1;34m
YELLOW=\x1b[33;01m
END=\033[0m

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

HEADER = ./libft/libft.h Makefile

#directorys
LIBFT_DIR = ./libft
GNL_DIR = ./gnl

LIBFT = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c	\
		ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_strrchr.c		\
		ft_strncmp.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c		\
		ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c ft_bzero.c		\
		ft_memcpy.c ft_memmove.c ft_memset.c ft_memchr.c ft_memcmp.c		\
		ft_calloc.c ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c			\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

OBJS = $(LIBFT:.c=.o)
#esto buscara los objetos .c dentro del directorio indicado. IMP! la barra 
OBJ = $(addprefix $(LIBFT_DIR)/,$(OBJS))

all : $(NAME)

$(NAME): $(OBJ) get_next_line $(HEADER)
	@$(AR) $(NAME) $(OBJ)
	@echo "$(GREEN)Libft DONE$(END)"

#lo mismo que poner: %.o : %.c pero aqui dentro del directorio nuevo
$(LIBFT_DIR)/%.o : $(LIBFT_DIR)/%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@
#	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

get_next_line:
	@$(MAKE) -C ./gnl --no-print-directory
	@echo "$(GREEN)Get_Next_Line DONE$(END)"

clean:	
	@$(RM) $(OBJ)
	@$(MAKE) -C ./gnl clean --no-print-directory
	@echo "$(RED)Libft objs$< deleted $(END)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./gnl fclean --no-print-directory
	@echo "$(RED)Libft exec deleted$(END)"

re:	fclean all

.PHONY: all clean fclean re get_next_line
