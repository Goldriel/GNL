/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:52:17 by jarrakis          #+#    #+#             */
/*   Updated: 2021/11/26 18:37:44 by jarrakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h> // use print for test begin del
#include<unistd.h>
#include<fcntl.h> // use open for test begin del
#include<stdlib.h>
#include"get_next_line.h"

static char	*process(char **save)
{
	int		i;
	int		j;
	char	*ret;
	char	*tmp;

	if (!*save)
		return (0);
	if (!ft_strchr(*save, '\n'))
	{
		ret = ft_substr(*save, 0, ft_strlen(*save));
		free(*save);
		*save = NULL;
		return (ret);
	}
	i = ft_strlen(*save);
	j = ft_strlen(ft_strchr(*save, '\n'));
	ret = ft_substr(*save, 0, i - j + 1);
	tmp = *save;
	*save = ft_substr(ft_strchr(*save, '\n'), 1, j - 1);
	free(tmp);
	return (ret);
}

static void	read_line(int fd, char *line, char **save)
{
	ssize_t	i;
	char	*temp;

	if (!*save || !ft_strchr(*save, '\n'))
	{
		i = read(fd, line, BUFFER_SIZE);
		while (i > 0)
		{
			line[i] = '\0';
			if (!*save)
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
	if (!(BUFFER_SIZE <= 0) && !(fd < 0) && !(read(fd, line, 0) == -1))
	{
		read_line(fd, line, &save);
		return (process(&save));
	}
	else
	{
		free(line);
		return (NULL);
	}
}

/*
 * main for test
 */
/*
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
*/