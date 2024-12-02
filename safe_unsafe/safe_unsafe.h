#ifndef SAFE_UNSAFE_H
# define SAFE_UNSAFE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char		*get_next_line(int fd);
char		*ft_fill_line(char *buffer, int fd);
void		*ft_calloc(size_t count, size_t size);
char		*ft_read_line(char *line_buffer);
int			ft_strlen(const char	*str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_update(char *buffer);
char		*ft_free(char *buffer);
char		*ft_joinfree(char *buffer, char *aux);
bool        is_sorted_descending(int *num, int size);
bool        is_sorted_ascending(int *num, int size);
bool         is_no_duplicate(int *arr, int size);
bool        is_valid(int *arr, int size);

#endif