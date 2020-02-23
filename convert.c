/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odelvaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:54:08 by odelvaux          #+#    #+#             */
/*   Updated: 2020/02/23 12:23:01 by odelvaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "mylib.h"

void	ft_write_nbr_into_ltrs(char *nbr, char *buffer)
{
	char 	*start_str;
	int 	i;


	start_str = ft_strstr(buffer, nbr);
	i = 0;
	while (start_str[i] && start_str[i] != '\n')
	{
		if (start_str[i] >= 'a' && start_str[i] <= 'z')
			write(1, &start_str[i], 1);
		i++;	
	}
}

void	ft_write_nbr_2digits(char *nbr, char *buffer)
{
	int		frst_dgt;
	char	*frst_dgt_char;
	int		snd_dgt;
	char	*snd_dgt_char;
	int 	size;

	//printf("NBR : %s\n", nbr);

	size = ft_strlen(nbr);
	if ((size == 2 && nbr[0] != '1' && nbr[1] != '0'))
	{
		frst_dgt = (nbr[0] - 48) * 10;
		//printf("FIRST DIGIT : %d\n", frst_dgt);
		frst_dgt_char = ft_itoa(frst_dgt);
		//printf("FIRST DIGIT CHAR : %s\n", frst_dgt_char);
		ft_write_nbr_into_ltrs(ft_strstr(buffer, frst_dgt_char), buffer);
		write(1, "-", 1);
		snd_dgt = (nbr[1] - 48);
		//printf("SECOND DIGIT : %d\n", snd_dgt);
		snd_dgt_char = ft_itoa(snd_dgt);
		//printf("SECOND DIGIT CHAR : %s\n", snd_dgt_char);
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

	i = -3;
	size = ft_strlen(nbr);
	while (size > 0)
	{
		// Si le nombre comporte plus d'un chiffre et que le premier chiffre nest pas un 0 !
		if (size > 1 && nbr[0] == '0')
		{
			write(1, "Format Number not allowed !", 27);
			break;
		}
		// Si le nombre est un nombre a un chiffre.
		if (size % 3 == 1)
		{
			i = i + 1;
			printf("1 - SIZE : %d\n", size);
			frst_nbr = (nbr[i] - 48);
			frst_nbr_char = ft_itoa(frst_nbr);
			ft_write_nbr_into_ltrs(ft_strstr(buffer, frst_nbr_char), buffer);
			size = size - 1;
		}
		// Si le nombre est un nombre a 2 chiffres.
		else if (size % 3 == 2)
		{
			i = i + 2;
			printf("2 - SIZE : %d\n", size);
			nbr_2dgs = ((nbr[i] - 48) * 10) + (nbr[i + 1] - 48);
			nbr_2dgs_char = ft_itoa(nbr_2dgs);
			ft_write_nbr_2digits(nbr_2dgs_char, buffer);
			size = size - 2;
		}
		// Si le nombre est un nombre a 3 chiffres.
		else if (size % 3 == 0)
		{
			i = i + 3;
			if (i >= 0)
			{
				frst_nbr = (nbr[i]- 48);
				frst_nbr_char = ft_itoa(frst_nbr);
				ft_write_nbr_into_ltrs(ft_strstr(buffer, frst_nbr_char), buffer);
				write(1, " ", 1);
				ft_write_nbr_into_ltrs(ft_strstr(buffer, "100"), buffer);
				if (nbr[size - 1] == '0' && nbr[size - 2] == '0')
				{
					size = size - 3;
					break;
				}
				// Sinon on affiche la dizaine et l'unite.
				else
				{
					write(1, " ", 1);
					nbr_2dgs = ((nbr[i + 1] - 48) * 10) + (nbr[i + 2] - 48);
					nbr_2dgs_char = ft_itoa(nbr_2dgs);
					ft_write_nbr_2digits(nbr_2dgs_char, buffer);
				}
			}
			else
			{
				// Affiche le chiffre des centaines directement suivis du mot 'cent'.
				printf("0 -SIZE : %d\n", size);
				frst_nbr = (nbr[size - 3]- 48);
				frst_nbr_char = ft_itoa(frst_nbr);
				ft_write_nbr_into_ltrs(ft_strstr(buffer, frst_nbr_char), buffer);
				write(1, " ", 1);
				ft_write_nbr_into_ltrs(ft_strstr(buffer, "100"), buffer);
				// Si l'unite et la dizaine valent 0, on s'arrete.
				if (nbr[size - 1] == '0' && nbr[size - 2] == '0')
				{
					size = size - 3;
					break;
				}
				// Sinon on affiche la dizaine et l'unite.
				else
				{
					write(1, " ", 1);
					nbr_2dgs = ((nbr[size - 2] - 48) * 10) + (nbr[size - 1] - 48);
					nbr_2dgs_char = ft_itoa(nbr_2dgs);
					ft_write_nbr_2digits(nbr_2dgs_char, buffer);
				}

			}
			size = size - 3;
		}
		else
			size = 0;
	}
}
