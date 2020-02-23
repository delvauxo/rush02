/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odelvaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 20:33:45 by odelvaux          #+#    #+#             */
/*   Updated: 2020/02/23 21:52:09 by odelvaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

char	*ft_open_read_default(void)
{
	int		fd;
	char	*buffer;
	int		file_read;
	int		file_size;

	if (!(buffer = malloc((sizeof(char) * 2048))))
		return (0);
	file_size = 0;
	fd = open("numbers.dict", O_RDONLY);
	if ((file_read = read(fd, buffer, 2048)) == -1)
		write(1, "Error\n", 6);
	else
	{
		file_size = file_read;
		close(fd);
	}
	return (buffer);
}

char	*ft_open_read_argv(char *dico)
{
	int		fd;
	char	*buffer;
	int		file_read;
	int		file_size;

	if (!(buffer = malloc((sizeof(char) * 2048))))
		return (0);
	file_size = 0;
	fd = open(dico, O_RDONLY);
	if ((file_read = read(fd, buffer, 2048)) == -1)
		write(1, "Error\n", 6);
	else
	{
		file_size = file_read;
		close(fd);
	}
	return (buffer);
}
