/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:51:48 by jarrakis          #+#    #+#             */
/*   Updated: 2021/11/23 20:57:48 by jarrakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 150
# endif

#include<stddef.h>

char	*get_next_line(int fb);

char	*ft_strchr(const char *s, int c);

char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlen(const char *c);

char	*ft_strjoin(char const *s1, char const *s2);

#endif