CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

SRC0 = *.c
OBJ0 =   $(SRC0:.c=.o)
NAME0 =  hsh

all: $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)

test:
	$(CC) $(SRC0) -o $(NAME0)

clean:
	$(RM) *~ \#*\# \.\#* $(NAME0) $(OBJ)

re: clean all

lint:
	betty $(SRC)

.PHONY: all test clean re lint
