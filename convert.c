/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odelvaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:54:08 by odelvaux          #+#    #+#             */
/*   Updated: 2020/02/23 23:02:44 by odelvaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mylib.h"

void	ft_write_nbr_into_ltrs(char *nbr, char *buffer)
{
	char	*start_str;
	int		i;
	int		size;

	start_str = ft_strstr(buffer, nbr);
	size = ft_strlen(nbr);
	i = 0;
	while (start_str[i] && start_str[i] != '\n')
	{
		while (start_str[i] != ':')
			i++;
		if (start_str[i] == ':')
			i++;
		while (start_str[i] == ' ')
			i++;
		while (start_str[i] >= 32 && start_str[i] <= 126)
		{
			write(1, &start_str[i], 1);
			i++;
		}
	}
}

void	ft_write_nbr_2digits(char *nbr, char *buffer)
{
	int		frst_dgt;
	char	*frst_dgt_char;
	int		snd_dgt;
	char	*snd_dgt_char;
	int		size;

	size = ft_strlen(nbr);
	if ((size == 2 && nbr[0] != '1' && nbr[1] != '0'))
	{
		frst_dgt = (nbr[0] - 48) * 10;
		frst_dgt_char = ft_itoa(frst_dgt);
		ft_write_nbr_into_ltrs(ft_strstr(buffer, frst_dgt_char), buffer);
		write(1, "-", 1);
		snd_dgt = (nbr[1] - 48);
		snd_dgt_char = ft_itoa(snd_dgt);
		ft_write_nbr_into_ltrs(ft_strstr(buffer, snd_dgt_char), buffer);
	}
	else
	{
		ft_write_nbr_into_ltrs(ft_strstr(buffer, nbr), buffer);
	}
}

void	ft_convert_full_nbr(char *nbr, char *buffer)
{
	int		size;
	int		nbr_2dgs;
	char	*nbr_2dgs_char;
	int		frst_nbr;
	char	*frst_nbr_char;
	int		i;

	i = 0;
	size = ft_strlen(nbr);
	while (size > 0)
	{
		if (size > 1 && nbr[0] == '0')
		{
			write(1, "Format Number not allowed !", 27);
			break ;
		}
		if (size % 3 == 1)
		{
			frst_nbr = (nbr[i] - 48);
			frst_nbr_char = ft_itoa(frst_nbr);
			ft_write_nbr_into_ltrs(ft_strstr(buffer, frst_nbr_char), buffer);
			i = i + 1;
			size = size - 1;
			ft_write_number_power(size, buffer);
		}
		else if (size % 3 == 2)
		{
			nbr_2dgs = ((nbr[i] - 48) * 10) + (nbr[i + 1] - 48);
			nbr_2dgs_char = ft_itoa(nbr_2dgs);
			ft_write_nbr_2digits(nbr_2dgs_char, buffer);
			i = i + 2;
			size = size - 2;
			ft_write_number_power(size, buffer);
		}
		else if (size % 3 == 0)
		{
			frst_nbr = (nbr[i] - 48);
			frst_nbr_char = ft_itoa(frst_nbr);
			if (nbr[i] != '0')
			{
				write(1, " ", 1);
				ft_write_nbr_into_ltrs(ft_strstr(buffer,
							frst_nbr_char), buffer);
				write(1, " ", 1);
				ft_write_nbr_into_ltrs(ft_strstr(buffer, "100"), buffer);
			}
			nbr_2dgs = ((nbr[i + 1] - 48) * 10) + (nbr[i + 2] - 48);
			nbr_2dgs_char = ft_itoa(nbr_2dgs);
			if (nbr[i + 1] != '0' || nbr[i + 2] != '0')
			{
				write(1, " ", 1);
				ft_write_nbr_2digits(nbr_2dgs_char, buffer);
			}
			size = size - 3;
			if ((size >= 3) && (nbr[i] != '0' || nbr[i + 1] != '0'
						|| nbr[i + 2] != '0'))
				ft_write_number_power(size, buffer);
			i = i + 3;
		}
	}
}
