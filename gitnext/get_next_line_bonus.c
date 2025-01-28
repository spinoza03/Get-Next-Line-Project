/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:42:11 by ilallali          #+#    #+#             */
/*   Updated: 2025/01/28 14:26:44 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	if (s == NULL)
		return (0);
	while (s[l])
	{
		l++;
	}
	return (l);
}

char	*read_line(int fd, char *buffer)
{
	char	*tmp;
	ssize_t	bytes_read;

	bytes_read = 1;
	tmp = malloc((size_t)BUFFER_SIZE + 1);
	if (!tmp)
		return (free(buffer), NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(tmp);
			return (free(buffer), NULL);
		}
		tmp[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (!buffer || ft_strchr(buffer, '\n') != -1)
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*extract_line(char **buffer)
{
	char	*line;
	char	*remaining;
	size_t	i;

	if (!*buffer || **buffer == '\0')
		return (NULL);
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	line = malloc(i + 1 + ((*buffer)[i] == '\n'));
	if (!line)
		return (NULL);
	ft_strlcpy(line, *buffer, i + 2);
	if ((*buffer)[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	if ((*buffer)[i] != '\0')
		remaining = ft_strdup(*buffer + i);
	else
		remaining = NULL;
	free(*buffer);
	*buffer = remaining;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 10240)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(&buffer[fd]);
	if (!line && buffer[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
// #include <stdio.h>
// # include <fcntl.h>
// int main()
// {
//     int fd1, fd2, fd3;
//     char *line;

//     // Open multiple files
//     fd1 = open("file1.txt", O_RDONLY);
//     fd2 = open("file2.txt", O_RDONLY);
//     fd3 = open("file3.txt", O_RDONLY);

//     if (fd1 < 0 || fd2 < 0 || fd3 < 0) {
//         perror("Error opening files");
//         return (EXIT_FAILURE);
//     }

//     // Read and print lines alternately from the files
//     printf("Reading lines from file1.txt, file2.txt, and file3.txt:\n");
//     for (int i = 0; i < 5; i++) {
//         if ((line = get_next_line(fd1)) != NULL) {
//             printf("File1: %s", line);
//             free(line);
//         }
//         if ((line = get_next_line(fd2)) != NULL) {
//             printf("File2: %s", line);
//             free(line);
//         }
//         if ((line = get_next_line(fd3)) != NULL) {
//             printf("File3: %s", line);
//             free(line);
//         }
//     }

//     // Close files
//     close(fd1);
//     close(fd2);
//     close(fd3);

//     return (EXIT_SUCCESS);
// }