CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRC = main.c session.c store.c
OBJ = $(SRC:.c=.o)
NAME = secure_data

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(NAME)

oclean:
	rm -f $(OBJ)

fclean: clean oclean
