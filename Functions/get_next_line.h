/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:06:49 by diegrod2          #+#    #+#             */
/*   Updated: 2024/11/07 13:06:49 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE	10
# endif

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*get_next_line(int fd);
char	*read_from_file(char *basin_buffer, int fd);
char	*append_buffer(char *basin_buffer, char *read_buffer);
char	*extract_line(char *basin_buffer);
char	*obtain_remaining(char *basin_buffer);

#endif