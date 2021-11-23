/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:52:17 by jarrakis          #+#    #+#             */
/*   Updated: 2021/11/23 20:56:37 by jarrakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h> // use print for test begin del
#include<unistd.h>
#include<fcntl.h> // use open for test begin del
#include<stdlib.h>
#include"get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;
	int			i;

	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	if ((BUFFER_SIZE < 1) || (fd == -1) || (read(fd, line, 0) == -1))
	{
		free(line);
		return (NULL);
	}
	i = read(fd, line, BUFFER_SIZE);
	printf("%d\n", i);
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
	return (0);
}
