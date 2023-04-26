CC = gcc
RM = rm -f
BETTY = betty
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format

SRC0=   *.c
OBJ0=   $(SRC0:.c=.o)
NAME0=  hsh

all: $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

test:
	$(CC) $(SRC0) -o $(NAME0)

clean:
	$(RM) *~ $(NAME)

oclean:
	$(RM) $(OBJ)

fclean:
	$(RM) *~ $(NAME)
	$(RM) $(OBJ)

re: oclean all
