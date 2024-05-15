# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 13:08:42 by yanaranj          #+#    #+#              #
#    Updated: 2024/05/13 14:50:59 by yanaranj         ###   ########.fr        #
#                                                                              #
# **
# ************************************************************************** #

#COLORS#
GREEN=\033[1;32m
RED=\033[1;31m
BLUE=\033[1;34m
YELLOW=\x1b[33;01m
END=\033[0m

NAME = gnl.a
CFLAGS = cc -Wall -Werror -Wextra
AR = ar -rcs
RM = rm -f

HEADER = get_next_line.h Makefile

SRC = get_next_line.c get_next_line_utils.c
OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) $(HEADER)
	@$(AR) $(NAME) $(OBJS)

%.o : %.c
	@$(CFLAGS) -c $< -o $@
	@echo "$(GREEN)File $< compiled $(END)"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED)GNL objs$< deleted $(END)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)GNL exec deleted$(END)"

re: fclean all

.PHONY: all clean fclean re
