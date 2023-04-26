CC = gcc
RM = rm -f
BETTY = betty
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format

SRC0 =   shell.c make_token.c read_line.c run_command.c prompt.c trim_line.c _execv.c
OBJ0 =   $(SRC0:.c=.o)
NAME0 =  hsh

all: $(OBJ0)
	$(CC) $(CFLAGS) $(OBJ0) -o $(NAME0)

test:
	$(CC) $(SRC0) -o $(NAME0)

clean:
	$(RM) *~ $(NAME0)

oclean:
	$(RM) $(OBJ0)

fclean:
	$(RM) *~ $(NAME0)
	$(RM) $(OBJ0)

re: oclean all
