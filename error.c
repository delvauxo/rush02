/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odelvaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:56:58 by odelvaux          #+#    #+#             */
/*   Updated: 2020/02/23 21:50:23 by odelvaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mylib.h"

int		ft_check_number(char *nbr)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen(nbr);
	if (size > 39)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
		{
			write(1, "Error\n", 7);
			return (0);
		}
		i++;
	}
	return (1);
}
