# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/30 11:55:59 by edegarci          #+#    #+#              #
#    Updated: 2024/06/06 12:58:51 by edegarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	cc

CCFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -rf

SRCS =		ft_printf.c\
			ft_functions_1.c\
			ft_functions_2.c\

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@ar crs $(NAME) $(OBJS)

all: $(NAME)

%.o : %.c
	@$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	@echo "Remove .o  ..."
	@$(RM) $(OBJS)
	@echo "Done!"

fclean: clean
	@echo "Remove lib ..."
	@rm -f $(NAME)
	@echo "Done!"

re: fclean all

.PHONY: all clean fclean re
