# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybenbrai <ybenbrai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 19:48:26 by kbahrar           #+#    #+#              #
#    Updated: 2019/10/18 00:30:53 by ybenbrai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC =  src/ft_check.c src/main.c src/window.c src/rotation.c
OBJ = $(SRC:.c=.o)
LIBF = libft/libft.a
LIBS = fdf.a

all:$(NAME)

$(NAME): $(OBJ)
	make -C libft
	ar rc $(LIBS) $(OBJ)
	gcc -Wall -Wextra -Werror -I /usr/local/include $(SRC) -L /usr/local/lib -lmlx -L libft/ -lft -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(LIBS)
	make fclean -C libft/

fclean: clean
	rm -rf $(NAME)

re: fclean all
	make re -C libft/

%.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@
