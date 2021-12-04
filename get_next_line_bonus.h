/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarrakis <jarrakis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:39:58 by jarrakis          #+#    #+#             */
/*   Updated: 2021/12/04 20:41:12 by jarrakis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include<stddef.h>
# include<stdlib.h>
# include<unistd.h>

char	*get_next_line(int fb);

char	*ft_strchr(const char *s, int c);

/*
 ** ft_substr
 ** returns the portion of string specified by
 ** the start and length parameters.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlen(const char *c);

/*
 ** ft_strjoin
 ** concatenates two strings and returns a pointer
 */

char	*ft_strjoin(char const *s1, char const *s2);

/*
 ** ft_strdup
 ** creates a copy of the string of
 ** the heap and returns a pointer to the new string
 */

char	*ft_strdup(const char *s1);

#endif
