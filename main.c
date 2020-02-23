/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odelvaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:57:18 by odelvaux          #+#    #+#             */
/*   Updated: 2020/02/23 06:58:45 by odelvaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mylib.h"

int	main(int argc, char **argv)
{
	(void) argc;
	char *buffer;

	buffer = ft_open_read();
	ft_convert_full_nbr(argv[1], buffer);
	return (0);
}
