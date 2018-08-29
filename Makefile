NAME=a.out

ASMSRC=ft_bzero.s
CSRC=ft_bzero_test.c
OBJ=$(ASMSRC:.s=.o) $(CSRC:.c=.o)

CC = gcc
CCFLAGS = -Wall -Werror -Wextra

$(NAME):
	nasm -f elf64 $(ASMSRC)
	$(CC) $(CCFLAGS) -g -c $(CSRC)
	$(CC) $(CCFLAGS) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

runtests: $(NAME)
	./$(NAME)
	echo $?
