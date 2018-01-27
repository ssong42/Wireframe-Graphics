# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/20 14:47:28 by ssong             #+#    #+#              #
#    Updated: 2018/01/27 12:52:44 by ssong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Werror -Wextra
SRCS = ./
INCLUDE = ./
FILES = readmap get_next_line image mouse_hook main
LIB = libft/libft.a miniLibX/libmlx.a
MLXLINK = -framework OpenGl -framework Appkit

CFILES = $(patsubst %, $(SRCS)%.c, $(FILES))
OFILES = $(patsubst %, $(SRCS)%.c, $(FILES))

all: $(LIB) $(MLXLINK) $(NAME)

$(LIB):
	make -C libft/.
	
$(MLXLINK):
	make -C miniLibX/.

$(NAME):
	gcc $(FLAGS) $(CFILES) $(LIB) -I. -I miniLibX/. $(MLXLINK) -o $(NAME)

clean:
	rm -f fdf

fclean: clean
	make fclean -C ./libft
	make clean -C ./miniLibX

re: fclean all
