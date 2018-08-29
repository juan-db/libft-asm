NAME = libfts.a
SOURCE = ft_bzero.s \
		 ft_isalpha.s
OBJECT = $(SOURCE:.s=.o)

TEST_NAME = tests
TEST_SOURCE = ft_bzero_test.c
TEST_OBJECT = $(TEST_SOURCE:.c=.o)

# CSRC=ft_bzero_test.c
# OBJ=$(ASMSRC:.s=.o) $(CSRC:.c=.o)

# CC = gcc
# CCFLAGS = -Wall -Werror -Wextra

AS = nasm
ASFLAGS = -f elf64

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

runtests: $(NAME) $(TEST_OBJECT)
	gcc -o $(TEST_NAME) $(TEST_OBJECT) -L. -lfts
	./$(TEST_NAME)

cleantests:
	rm -rf $(TEST_OBJECT)

fcleantests: cleantests
	rm -rf $(TEST_NAME)