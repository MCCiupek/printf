# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 15:18:07 by mciupek           #+#    #+#              #
#    Updated: 2020/12/11 12:16:50 by mciupek          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c\
		display_char.c\
		display_hex.c\
		display_hex_maj.c\
		display_int.c\
		display_ptr.c\
		display_str.c\
		display_uint.c\
		ft_dec2hex.c\
		ft_flags.c\
		ft.c\

DIRINC		= includes/

DIRSRC		= srcs/

DIRLIB		= libft/

LIB		= $(DIRLIB)libft.a

CC		= clang

RM		= rm -f

FLAGS		= -Wall -Wextra -Werror# -g3 -fsanitize=address

INC		= -I $(DIRINC) #$(DIRLIB)

OBJ		= $(addprefix $(DIRSRC), $(SRCS:.c=.o))

$(DIRSRC)%.o:	$(DIRSRC)%.c
	$(CC) $(FLAGS) $(INC) -o $@ -c $<

$(NAME):	$(LIB) $(OBJ)
	cp $(LIB) $(NAME)
	@echo "libft.a -> libftprintf.a"
	ar -rcs $(NAME) $(OBJ)

$(LIB):
	$(MAKE) -C $(DIRLIB)

all:		$(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(DIRLIB)

fclean:		clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(DIRLIB)

re:			fclean all

.PHONY:		all clean fclean re
