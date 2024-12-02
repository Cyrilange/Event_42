#include "safe.h"


int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = '\0';
	return (join);
}

char	*ft_joinfree(char *buffer, char *aux)
{
	char	*temp;

	temp = ft_strjoin(buffer, aux);
	if (!temp)
		return (ft_free(buffer));
	else if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	return (temp);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char		*result;
	size_t		i;

	i = 0;
	result = malloc(count * size);
	if (result != NULL)
	{
		while (i < size * count)
		{
			result[i] = 0;
			i++;
		}
	}
	return ((void *)result);
}


char	*ft_free(char *buffer)
{
	free(buffer);
	buffer = NULL;
	return (NULL);
}

char	*ft_read_line(char *buffer)
{
	char	*left;
	ssize_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	left = (char *)ft_calloc(i + 1 + (buffer[i] == '\n'), 1);
	if (!left)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		left[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		left[i] = '\n';
	return (left);
}

char	*ft_fill_line(char *buffer, int fd)
{
	ssize_t	reed;
	char	*temp;

	if (!buffer)
	{
		buffer = ft_calloc(1, 1);
		if (!buffer)
			return (NULL);
	}
	temp = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!temp)
		return (ft_free(buffer));
	reed = 1;
	while ((!ft_strchr(temp, '\n')) && reed > 0)
	{
		reed = read(fd, temp, BUFFER_SIZE);
		if (reed == -1)
			return (ft_free(buffer));
		temp[reed] = '\0';
		buffer = ft_joinfree(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	free(temp);
	return (buffer);
}

char	*ft_update(char *buffer)
{
	int		i;
	int		j;
	char	*upt;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (ft_free(buffer));
	upt = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!upt)
		return (ft_free(buffer));
	i++;
	j = 0;
	while (buffer[i])
		upt[j++] = buffer[i++];
	free(buffer);
	return (upt);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_fill_line(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_read_line(buffer);
	buffer = ft_update(buffer);
	return (line);
}