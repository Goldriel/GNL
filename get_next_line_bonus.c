/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:40:01 by jarrakis          #+#    #+#             */
/*   Updated: 2021/12/04 20:41:12 by jarrakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

static char	*add_save(size_t len, char **save, char **tmp, char **return_line)
{
	*return_line = ft_substr(*save, 0, len + 1);
	*tmp = ft_strdup(*save + len + 1);
	free(*save);
	*save = *tmp;
	if (!**save)
	{
		free(*save);
		*save = NULL;
	}
	return (*return_line);
}

static char	*return_line(ssize_t read_buff, char **save)
{
	char	*return_line;
	char	*tmp;
	size_t	len;

	if ((read_buff < 0) || (!read_buff && (!save || !*save)))
		return (NULL);
	len = 0;
	return_line = NULL;
	while ((*save)[len] != '\n' && (*save)[len])
		len++;
	if ((*save)[len] == '\n')
		return (add_save(len, save, &tmp, &return_line));
	return_line = ft_strdup(*save);
	free(*save);
	*save = NULL;
	return (return_line);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*save[FD_MAX];
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
		if (!save[fd])
			save[fd] = ft_strdup("");
		tmp = ft_strjoin(save[fd], buff);
		free(save[fd]);
		save[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
		read_buff = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (return_line(read_buff, &save[fd]));
}
