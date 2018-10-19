#ifndef LIBFTS_H
#define LIBFTS_H

#include <stddef.h>

void	ft_bzero(void* s, size_t n);
char*	ft_strcat(char* s1, const char* s2);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
// ft_toupper // TODO
// ft_tolower // TODO
int		ft_puts(const char* s);

size_t	ft_strlen(const char* s);
// ft_memset // TODO
// ft_memcpy // TODO
// ft_strdup // TODO

// ft_cat // TODO

#endif