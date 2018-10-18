NAME = libfts.a
SOURCE = ft_bzero.s \
		 ft_isalpha.s \
		 ft_isdigit.s \
		 ft_isalnum.s \
		 ft_isprint.s \
		 ft_strlen.s \
		 ft_puts.s \
		 ft_strcat.s
OBJECT = $(SOURCE:.s=.o)

TEST_NAME = tests
TEST_SOURCE = test/test.c \
			  test/ft_bzero_test.c \
			  test/ft_isalpha_test.c \
			  test/ft_isdigit_test.c \
			  test/ft_isalnum_test.c \
			  test/ft_isprint_test.c \
			  test/ft_strlen_test.c \
			  test/ft_puts_test.c \
			  test/ft_strcat_test.c
TEST_OBJECT = $(TEST_SOURCE:.c=.o)

AS = nasm
ASFLAGS = -f macho64

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
