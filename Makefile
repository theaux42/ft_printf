# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 14:09:48 by tbabou            #+#    #+#              #
#    Updated: 2024/01/17 22:04:53 by tbabou           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	ft_printf.c print_char.c print_hexa.c print_nbr.c\
				print_ptr.c print_str.c print_utils.c
OBJS		=	$(addprefix $(DIR_OUT)/,$(SRC:.c=.o))

DIR_SRCS	=	./
DIR_OUT		=	obj
DIR_LIBFT	=	libft
HEADERS		=	includes

NAME		=	libftprintf.a
LIBFT_NAME	=	libft.a
LIBFT		=	$(DIR_LIBFT)/$(LIBFT_NAME)

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LIB			=	ar rc
RM			=	rm -f

all:				$(NAME)

bonus:				$(NAME)

$(NAME):			$(OBJS)
					$(LIB) $(NAME) $(OBJS)

$(DIR_OUT)/%.o:		$(DIR_SRCS)/%.c | $(DIR_OUT)
					$(CC) $(CFLAGS) -I $(HEADERS) -o $@ -c $<

$(DIR_OUT):
					mkdir -p $(DIR_OUT)

clean:				
					rm -f $(OBJS)
					rm -rf $(DIR_OUT)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re libft bonus