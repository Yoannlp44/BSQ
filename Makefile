##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##


NAME = bsq

SRC = 	src/main.c 				\
		src/get_file.c			\
		src/check_error.c		\
		src/do_bsq.c

CFLAGS = -W -Wall -Wextra -I ./include

OBJ = $(SRC:%.c=%.o)

LIB = -L ./lib/my -lmy

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./lib/my/
	$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./lib/my

fclean:	clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./lib/my

re:	fclean all
