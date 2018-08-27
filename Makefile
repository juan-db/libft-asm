NAME=a.out

SRC=ft_bzero.s
OBJ=$(SRC:.s=.o)

$(NAME):
	nasm -f elf64 $(SRC)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all