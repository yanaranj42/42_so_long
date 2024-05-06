# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 14:53:21 by yanaranj          #+#    #+#              #
#    Updated: 2024/05/06 15:06:29 by yanaranj         ###   ########.fr        #
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
RM = rm -rf

SRCS = #.c files
OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)

SRCS_LIBFT = ./libft/libft.a
MAKE_LIBFT = make -C libft

MLX = ./minilibx/libmlx.h
MLX_FLAGS = -L ./minilibx -lmlx -framework OpenGL -framework AppKit

%.o: %.c Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

all: make_lib $(NAME) $(MLX) $(SRCS_LIBFT)

make_lib:
	@$(MAKE_LIBFT) --no-print-directory

make_mlx:
	@$(MAKE) -C ./minilibx --no-print-directory

-include $(DEPS)
$(NAME): $(OBJS) $(SRCS_LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(SRCS_LIBFT) -o $(NAME)
	@echo "$(GREEN)SO_LONG DONE$(END)"

clean:
	@$(RM) $(OBJS) $(DEPS)
	@$(MAKE) -C ./libft clean --no-print-directory
	@$(MAKE) -C ./minilibx clean --no-print-directory
	@echo "$(RED)OBJECTS DELETED$(END)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./libft fclean --no-print-directory
	@$(MAKE) -C ./minilibx fclean --no-print-directory
	@echo "$(RED)EXEC DELETED $(END)"

re: fclean all

.PHONY: all clean fclean re
