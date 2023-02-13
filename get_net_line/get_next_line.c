/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:25:17 by zachaban          #+#    #+#             */
/*   Updated: 2023/02/13 12:11:56 by zachaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *str)//prend une string en parametre
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);// protectio malloc

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save(char *str)
{
	int		i;
	int		j;
	char	*rest_saved;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rest_saved = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest_saved)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		rest_saved[j++] = str[i++];
	rest_saved[j] = '\0';
	free(str);
	return (rest_saved);
}

char	*ft_read_save(int fd, char *str)
{
	char	*buffer;
	int		size_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	size_read = 1;
	while (!ft_strchr(str, '\n') && size_read != 0)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[size_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_save(fd, str);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_save(str);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main (void)
// {
// 	int	fd;
// 	char	*str;
// 	fd = open("get_next_line_bonus.c", O_RDONLY);
// 	str = get_next_line(fd);
// 		while (str)
// 		{
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd);
// 		}
// 	close(fd);
// }




