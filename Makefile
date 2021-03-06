NAME = libfts.a
SOURCE = source/ft_bzero.s \
		 source/ft_strcat.s \
		 source/ft_isalpha.s \
		 source/ft_isdigit.s \
		 source/ft_isalnum.s \
		 source/ft_isascii.s \
		 source/ft_isprint.s \
		 source/ft_toupper.s \
		 source/ft_tolower.s \
		 source/ft_puts.s \
		 source/ft_strlen.s \
		 source/ft_memset.s \
		 source/ft_memcpy.s \
		 source/ft_strdup.s \
		 source/ft_cat.s
INCLUDE = -Iinclude
OBJECT = $(SOURCE:.s=.o)

TEST_NAME = tests
TEST_SOURCE = test/test.c \
			  test/ft_bzero_test.c \
			  test/ft_strcat_test.c \
			  test/ft_ctype_test.c \
			  test/ft_tox_test.c \
			  test/ft_puts_test.c \
			  test/ft_strlen_test.c \
			  test/ft_memset_test.c \
			  test/ft_memcpy_test.c \
			  test/ft_strdup_test.c \
			  test/ft_cat_test.c
TEST_INCLUDE = -Itest

TEST_OBJECT = $(TEST_SOURCE:.c=.o)

AS = nasm
ASFLAGS = -f macho64

CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INCLUDE) $(TEST_INCLUDE)

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

.PHONY: all clean fclean re runtests cleantests fcleantests
