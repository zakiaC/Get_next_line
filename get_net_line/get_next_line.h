/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zachaban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:24:41 by zachaban          #+#    #+#             */
/*   Updated: 2023/02/09 12:24:11 by zachaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
#endif

char		*get_next_line(int fd);
char		*ft_read_and_save(int fd, char *save);
char		*ft_save(char *save);
char		*ft_get_line(char *save);
void		*ft_calloc(size_t nmemb, size_t n);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);

#endif
