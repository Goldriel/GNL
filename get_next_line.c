/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:52:17 by jarrakis          #+#    #+#             */
/*   Updated: 2021/11/16 19:59:02 by jarrakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h> // use print for test begin del
#include<unistd.h>
#include<fcntl.h> // use open for test begin del
#include<stdlib.h>
#include"get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	int		read_line;

	read_line = read(fd, &line, BUFFER_SIZE);
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
	return (0);
}
