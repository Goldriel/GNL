/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:52:17 by jarrakis          #+#    #+#             */
/*   Updated: 2021/12/01 21:52:35 by jarrakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h> // use print for test begin del
#include<unistd.h>
#include<fcntl.h> // use open for test begin del
#include<stdlib.h>
#include"get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*save;
	char		*tmp;
	ssize_t		read_buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	read_buff = read(fd, buff, BUFFER_SIZE);
	while (read_buff > 0)
	{
		buff[read_buff] = '\0';
		if (!save)
			save = ft_strdup("");
		tmp = ft_strjoin(save, buff);
		free(save);
		save = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
		read_buff = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (save);
}

/*
 * main for test

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("../test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	line = get_next_line(fd);
	printf("%s\n", line);
	close(fd);
	return (0);
}
*/