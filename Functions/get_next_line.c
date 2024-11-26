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

# include "get_next_line.h"

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
