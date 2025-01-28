/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkrainyk <mkrainyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:57:43 by mkrainyk          #+#    #+#             */
/*   Updated: 2024/12/10 19:33:42 by mkrainyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_store(int fd, char *buffer);
char	*extract_line(char *buffer);
char	*upd_buffer(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_store(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = upd_buffer(buffer);
	return (line);
}

char	*read_and_store(int fd, char *buffer)
{
	char		*buffer_temp;
	ssize_t		bytes_read;

	buffer_temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_temp)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer_temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(buffer_temp);
			return (NULL);
		}
		buffer_temp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, buffer_temp);
	}
	free(buffer_temp);
	return (buffer);
}

char	*extract_line(char *buffer)
{
	char	*line;
	char	*newline_pos;
	size_t	len;

	if (!buffer || !*buffer)
		return (NULL);
	newline_pos = ft_strchr(buffer, '\n');
	if (newline_pos)
		len = newline_pos - buffer + 1;
	else
		len = ft_strlen(buffer);
	line = ft_substr(buffer, 0, len);
	return (line);
}

char	*upd_buffer(char *buffer)
{
	char	*new_buffer;
	char	*newline_pos;
	size_t	len;

	newline_pos = ft_strchr(buffer, '\n');
	if (!newline_pos)
	{
		free(buffer);
		return (NULL);
	}
	len = newline_pos - buffer + 1;
	new_buffer = ft_substr(buffer, len, ft_strlen(buffer) - len);
	free(buffer);
	return (new_buffer);
}

/*int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	(void)ac;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return 0;
}*/
