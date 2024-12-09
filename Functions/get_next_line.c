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
char *append_buffer(char *basin_buffer, char *read_buffer)
{
    char *temp;

    temp = ft_strjoin(basin_buffer, read_buffer);
    if (!temp)
        return (NULL);
    free(basin_buffer);
    return (temp);
}

char *read_from_file(char *basin_buffer, int fd)
{
    char *cup_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    int bytes_read;

    if (!cup_buffer)
        return (NULL);
    while ((bytes_read = read(fd, cup_buffer, BUFFER_SIZE)) > 0)
    {
        cup_buffer[bytes_read] = '\0';
        basin_buffer = append_buffer(basin_buffer, cup_buffer);
        if (!basin_buffer || ft_strchr(basin_buffer, '\n'))
            break;
    }
    free(cup_buffer);
    if (bytes_read == -1 || !basin_buffer)
        free(basin_buffer);
    return ((bytes_read == -1 || !basin_buffer) ? NULL : basin_buffer);
}


char *get_next_line(int fd)
{
    static char *basin_buffer;
    char *line;

    if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    if (!basin_buffer)
        basin_buffer = ft_calloc(1, sizeof(char));
    if (!basin_buffer)
        return (NULL);

    if (!ft_strchr(basin_buffer, '\n'))
        basin_buffer = read_from_file(basin_buffer, fd);

    if (!basin_buffer || basin_buffer[0] == '\0')
    {
        free(basin_buffer);
        basin_buffer = NULL;
        return (NULL);
    }

    line = extract_line(basin_buffer);
    basin_buffer = obtain_remaining(basin_buffer);

    return (line);
}

char *extract_line(char *basin_buffer)
{
    char *line;
    int i;

    i = 0;
    while (basin_buffer[i] && basin_buffer[i] != '\n')
        i++;
    if (basin_buffer[i] == '\n')
        i++;
    line = strndup(basin_buffer, i);
    return (line);
}

char *obtain_remaining(char *basin_buffer)
{
    char *remaining;
    int i;

    i = 0;
    while (basin_buffer[i] && basin_buffer[i] != '\n')
        i++;
    if (basin_buffer[i] == '\n')
        i++;
    remaining = strdup(&basin_buffer[i]);
    if (!remaining)
        return (NULL);
    free(basin_buffer);
    return (remaining);
}
