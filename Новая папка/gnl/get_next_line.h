/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:44:48 by sam               #+#    #+#             */
/*   Updated: 2022/03/10 15:41:00 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
# endif

void	*ft_memcpy(void *dest, const void *src, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *str);
int		ft_strlen(const char *p);
char	*line_num(const char *s);
char	*get_next_line(int fd);

#endif