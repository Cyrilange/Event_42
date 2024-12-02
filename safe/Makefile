NAME = safe

CC = gcc
CFLAGS = -Wall -Wextra -Werror

GREEN = \033[0;92m
RED = \033[0;91m

SRC = main.c \
	  get_next_line.c \
	  safe.c \
	 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "${GREEN}Compiling is done for ${NAME}, you can now use it  ${RED}./safe_unsafe"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all