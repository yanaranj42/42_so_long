# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 14:07:07 by yanaranj          #+#    #+#              #
#    Updated: 2024/05/20 17:30:12 by yanaranj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS#
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m
YELLOW= \033[1;33m

NAME = so_long
CC = cc -g #-fsanitize=address
CFLAGS = -Wall -Werror -Wextra -MMD -I ./
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -L ./minilibx
LIBFT_FLAGS = -L ./mylibs -lft
RM = rm -rf

HEADER = Makefile so_long.h

SRCS = so_long_main.c check_map.c errors.c so_long_utils.c parsing_map.c \
	   window_management.c
OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)

#libs
SRCS_LIBFT = ./mylibs/libft/libft.h
SRC_GNL = ./mylibs/gnl/get_next_line.h
SRCS_MLX = ./minilibx/libmlx.h

#.a GNL check si pide el .a del libft
GNL = ./mylibs/gnl/gnl.a
LIB = ./mylibs/libft.a

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

all: make_lib make_mlx make_gnl $(NAME)

make_lib:
	@$(MAKE) -C ./mylibs --no-print-directory
make_gnl:
	@$(MAKE) -C ./mylibs/gnl --no-print-directory
make_mlx:
	@$(MAKE) -C ./minilibx --no-print-directory

-include $(DEPS)
$(NAME): $(OBJS) $(SRCS_LIBFT) $(SRC_GNL) $(HEADER)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIB) $(GNL) $(OBJS) -o $(NAME)
	@echo "$(GREEN)SO LONG DONE$(END)"

clean:
	@$(RM) $(OBJS) $(DEPS)
	@$(MAKE) -C ./mylibs clean --no-print-directory
	@$(MAKE) -C ./minilibx clean --no-print-directory
	@echo "$(RED)OBJECTS DELETED$(END)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./mylibs fclean --no-print-directory
	@echo "$(RED)EXEC DELETED $(END)"

re: fclean all

.PHONY: all clean fclean re
