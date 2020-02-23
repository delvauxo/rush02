/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odelvaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:57:18 by odelvaux          #+#    #+#             */
/*   Updated: 2020/02/23 21:51:04 by odelvaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

int		main(int argc, char **argv)
{
	char *buffer;

	if (argc > 3 || argc == 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	else if (argc == 2)
	{
		if (ft_check_number(argv[1]) == 0)
			return (0);
		buffer = ft_open_read_default();
		ft_convert_full_nbr(argv[1], buffer);
		free(buffer);
	}
	else if (argc == 3)
	{
		if (ft_check_number(argv[2]) == 0)
			return (0);
		buffer = ft_open_read_argv(argv[1]);
		ft_convert_full_nbr(argv[2], buffer);
		free(buffer);
	}
	return (0);
}
