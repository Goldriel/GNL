/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:52:17 by jarrakis          #+#    #+#             */
/*   Updated: 2021/11/25 21:08:26 by jarrakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h> // use print for test begin del
#include<unistd.h>
#include<fcntl.h> // use open for test begin del
#include<stdlib.h>
#include"get_next_line.h"

static void	read_line(int fd, char *line, char **save)
{
	ssize_t	i;
	char	*temp;

	if (*save != NULL || ft_strchr(*save, '\n') != NULL)
	{
		i = read(fd, line, BUFFER_SIZE);
		while (i > 0)
		{
			line[i] = '\0';
			if (*save != NULL)
				*save = ft_substr(line, 0, i);
			else
			{
				temp = *save;
				*save = ft_strjoin(*save, line);
				free(temp);
			}
			if (ft_strchr(line, '\n'))
				break ;
			i = read(fd, line, BUFFER_SIZE);
		}
	}
	free(line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	if ((BUFFER_SIZE <= 0) || (fd < 0) || (read(fd, line, 0) == -1))
	{
		free(line);
		return (NULL);
	}
	read_line(fd, line, &save);
	return (line);
}

/*
 * main for test
 */
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	printf("\n");
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	return (0);
}
