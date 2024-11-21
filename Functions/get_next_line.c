/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegrod2 <diegrod2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:47:20 by diegrod2          #+#    #+#             */
/*   Updated: 2024/11/21 11:47:20 by diegrod2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>

char  *get_next_line(int fd)
{
  int  bytes_read;
  char *cup_buffer;
  
  cup_buffer = ft_calloc (3 + 1, sizeof(char));
  if (!cup_buffer)
    return (NULL);
  bytes_read = read(fd, cup_buffer, 3);
  if (bytes_read <= 0)
    return (NULL);
  return (cup_buffer);
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
  int    fd;
  char  *next_line;
  int  count;

  count = 0;
  fd = open("example.txt", O_RDONLY);
  next_line = get_next_line(fd);
  count++;
  printf("[%d]:%s\n", count, next_line); //count is to show you the line numbers
  next_line = NULL;

  close(fd);
  return (0);
}