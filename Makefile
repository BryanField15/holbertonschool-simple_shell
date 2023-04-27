CC = gcc
BETTY = betty
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRC0 = *.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = hsh

all: $(OBJ0)
	$(BETTY) $(SRC0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)

test:
	$(CC) $(SRC0) -o $(NAME0)

clean:
	$(RM) *~ \#*\# \.\#* $(NAME0) $(OBJ0)

re: clean all

.PHONY: all test clean re
