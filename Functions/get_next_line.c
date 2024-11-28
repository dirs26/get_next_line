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

# include <stdio.h>
# include "get_next_line.h"

char  *read_from_file(int fd)
{
	int  bytes_read;
	char *cup_buffer;
	static int count = 1;
   
	printf("ft_calloc#[%d]---", count++);
   	cup_buffer = ft_calloc (3 + 1, sizeof(char));
   	if (cup_buffer == NULL)
		return (NULL);
	bytes_read = read(fd, cup_buffer, 3);
	if (bytes_read <= 0)
		return (free (cup_buffer), NULL);
  return (cup_buffer);
}

char *get_next_line(int fd)
{
 char *basin_buffer;

 basin_buffer = read_from_file(fd);
 return (basin_buffer);
}
