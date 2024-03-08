# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azahajur <azahajur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 18:44:02 by azahajur          #+#    #+#              #
#    Updated: 2023/07/02 20:19:08 by azahajur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Usamos la variable NAME para asignar el archivo que queremos crear
# "libft.a", que será el archivo que contenga nuestra librería dinámica.
NAME = libft.a

FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c\
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
		ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_split.c\

# Genera los archivos .o para cada archivo .c
OBJ = $(FILES:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
# Solo se compilan los archivos que han cambiado. (Es una regla de cancelación, evita que se recompilen archivos que no se han actualizado).
%.o: %.c
	gcc $(FLAGS) -c -o $@ $<
	
# Borra todos los archivos de la variable OBJ
clean:
	rm -f $(OBJ)
	
# Borra todos los archivos de la variable OBJ y NAME
fclean: clean
	rm -f $(NAME) $(OBJ)
	
# Hace un re-make, borra todo y ejecuta el Make como si fuera la primera vez.
re: fclean all 

# le dice al make que estos nombres no son archivos
.PHONY: re all fclean clean