NAME = libfts.a
SOURCE = ft_bzero.s \
		 ft_isalpha.s \
		 ft_isdigit.s
OBJECT = $(SOURCE:.s=.o)

TEST_NAME = tests
TEST_SOURCE = test/test.c \
			  test/ft_bzero_test.c \
			  test/ft_isalpha_test.c \
			  test/ft_isdigit_test.c
TEST_OBJECT = $(TEST_SOURCE:.c=.o)

AS = nasm
ASFLAGS = -f elf64

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I.

all: $(NAME)

$(NAME): $(OBJECT)
	ar rc $(NAME) $(OBJECT)

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Tests
runtests: $(NAME) $(TEST_OBJECT)
	gcc -o $(TEST_NAME) $(TEST_OBJECT) -L. -lfts
	./$(TEST_NAME)

cleantests:
	rm -rf $(TEST_OBJECT)

fcleantests: cleantests
	rm -rf $(TEST_NAME)