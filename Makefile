# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorea <lorea@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 21:10:40 by azahajur          #+#    #+#              #
#    Updated: 2024/05/15 08:49:47 by lorea            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FILES = $(shell find -type f -name "*.c")
LIBFT = include/Libft/libft.a

# Genera los archivos .o para cada archivo .c
OBJ = $(FILES:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc $(OBJ) $(LIBFT) -o $(NAME)
	
# Solo se compilan los archivos que han cambiado. (Es una regla de cancelación, evita que se recompilen archivos que no se han actualizado).
%.o: %.c
	gcc $(FLAGS) -c -o $@ $<
	
# Compila el make de Libft
$(LIBFT):
	make -C include/Libft
	
# Borra todos los archivos de la variable OBJ
clean:
	rm -f $(OBJ) 
	make -C include/Libft clean
	
# Borra todos los archivos de la variable OBJ y NAME
fclean: clean
	rm -f $(NAME) $(OBJ)
	make -C include/Libft fclean
	
# Hace un re-make, borra todo y ejecuta el Make como si fuera la primera vez.
re: fclean all 

# le dice al make que estos nombres no son archivos
.PHONY: re all fclean clean $(LIBFT)
