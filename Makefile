# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aymaatou <aymaatou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 15:26:00 by aymaatou          #+#    #+#              #
#    Updated: 2019/12/24 14:27:54 by aymaatou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

SRC = ./src/ft_{conv,flag,cs_conv,putdigit,puthex}.c ./tools/ft_{digit_tools,hex_tools,print_tools,tools}.c ./ft_printf.c
OBJ = ft_conv.o ft_cs_conv.o ft_digit_tools.o ft_flag.o ft_hex_tools.o ft_print_tools.o ft_printf.o ft_putdigit.o ft_puthex.o ft_tools.o
CC = gcc -Wall -Wextra -Werror -c
LB = ar rc

all : $(NAME).a

$(NAME).a:
	@$(CC) $(SRC)
	@$(LB) $(NAME).a $(OBJ)

clean :
	@rm -fr $(OBJ)

fclean : clean
	@rm -fr $(NAME).a

re : fclean all

#.PHONY : all clean fclean re $(NAME).a