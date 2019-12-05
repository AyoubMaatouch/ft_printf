# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aymaatou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 15:26:00 by aymaatou          #+#    #+#              #
#    Updated: 2019/12/05 15:41:08 by aymaatou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

SRC = *.c
OBJ = *.o

CC = gcc -Wall -Wextra -Werror

LB = ar rc
all : $(NAME)

$(NAME):
	@$(CC) -c $(SRC)
	@$(LB) $(NAME) $(OBJ)

clean :
	rm -fr $(OBJ)

fclean : clean
	rm -fr $(NAME)

re : fclean all

.PHONY : all clean fclean re $(NAME)
.SILENT: all clean fclean re $(NAME)
