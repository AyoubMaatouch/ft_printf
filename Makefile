# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aymaatou <aymaatou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 15:26:00 by aymaatou          #+#    #+#              #
#    Updated: 2019/12/13 15:36:31 by aymaatou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = *.c
OBJ = *.o

CC = gcc -Wall -Wextra -Werror

LB = ar rc
all : $(NAME)

$(NAME):
	@$(CC) -c $(SRC) ./tools/$(SRC) ./src/$(SRC)
	@$(LB) $(NAME) $(OBJ)

clean :
	rm -fr $(OBJ)

fclean : clean
	rm -fr $(NAME)

re : fclean all

.PHONY : all clean fclean re $(NAME)
.SILENT: all clean fclean re $(NAME)