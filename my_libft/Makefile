# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yanaranj <yanaranj@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 14:32:13 by yanaranj          #+#    #+#              #
#    Updated: 2024/05/06 16:43:00 by yanaranj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS# 
GREEN=\033[1;32m
RED=\033[1;31m
BLUE=\033[1;34m
YELLOW=\x1b[33;01m
END=\033[0m

NAME = libft.a
CFLAGS = gcc -Wall -Wextra -Werror
AR	= ar -rcs
RM = rm -f

HEADER = libft.h

#paths

LIBFT_SRC = ./libft
GNL_SRC = ./gnl

LIBF_SRC	=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c	\
		ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_strrchr.c		\
		ft_strncmp.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c		\
		ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c ft_bzero.c		\
		ft_memcpy.c ft_memmove.c ft_memset.c ft_memchr.c ft_memcmp.c		\
		ft_calloc.c ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c			\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

GNL_SRC = get_next_line.c get_next_line_utils.c

OBJS = $(notdir $(LIBFT_SRC:.c=.o)) $(notdir $(GNL_SRC:.c=.o))

DEPS = $(OBJS:%.o =%.d)
all : $(NAME)

-include $(DEPS)
$(NAME) : $(OBJS) $(HEADER)
	@$(AR) $(NAME) $(OBJS)

%.o	: %.c $(HEADER) Makefile
	$(CFLAGS) -c $< -o $@

clean:	
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME) $(OBJS_B)
	
re:	fclean all

.PHONY: all clean fclean re bonus
