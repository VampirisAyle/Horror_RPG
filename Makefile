##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## make
##
SRC = $(wildcard ./src/*.c) $(wildcard ./src/menu/*.c) \
    $(wildcard ./src/player/*.c) $(wildcard ./lib/*.c) \
	$(wildcard ./src/inventory/*.c) $(wildcard ./src/dynamic_light/*.c) \
	$(wildcard ./src/game/*.c) $(wildcard ./src/game/pause/*.c) \
	$(wildcard ./src/items/*.c) $(wildcard ./src/enemy/*.c) \
	$(wildcard ./src/main/*.c) $(wildcard ./src/save/*.c)

OBJ = $(SRC:.c=.o)

NAME = libmy.a

OUTPUT = my_rpg

INCLUDE = ./include/my.h

CFLAGS = -g -Wall -Wextra

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o $(OUTPUT) $(OBJ) -lcsfml-graphics -lcsfml-audio \
	-lcsfml-system -lcsfml-window -lm

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUTPUT)
	rm -f $(NAME)

re: fclean all
