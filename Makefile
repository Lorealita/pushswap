# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 21:10:40 by azahajur          #+#    #+#              #
#    Updated: 2024/03/08 02:48:09 by azahajur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FILES = push_swap.c op_stack_a.c op_stack_b.c op_stack_s.c ps_utils.c\
		ps_ft_cost.c\
		
LIBFT = Libft/libft.a

# Genera los archivos .o para cada archivo .c
OBJ = $(FILES:.c=.o)
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(LIBFT):
	MAKE -C Libft

$(NAME): $(OBJ) $(LIBFT)
	cc $(OBJ) $(LIBFT) -o $(NAME)
	
# Solo se compilan los archivos que han cambiado. (Es una regla de cancelación, evita que se recompilen archivos que no se han actualizado).
%.o: %.c
	gcc $(FLAGS) -c -o $@ $<
	
# Borra todos los archivos de la variable OBJ
clean:
	rm -f $(OBJ) 
	MAKE -C Libft clean

# Borra todos los archivos de la variable OBJ y NAME
fclean: clean
	rm -f $(NAME) $(OBJ)
	MAKE -C Libft fclean
	
# Hace un re-make, borra todo y ejecuta el Make como si fuera la primera vez.
re: fclean all 

# le dice al make que estos nombres no son archivos
.PHONY: re all fclean clean $(LIBFT)
