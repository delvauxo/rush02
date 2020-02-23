/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odelvaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:25:44 by odelvaux          #+#    #+#             */
/*   Updated: 2020/02/23 05:10:35 by odelvaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

/*
 *	Helper.c - 
*/

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strstr(char *nbr, char *to_find);
int		ft_iterative_power(int nb, int power);
int 	ft_len(long nb);
char	*ft_itoa(int nb);
int		ft_atoi(char *str);

/*
 *	Convert.c - Convert
*/

void	ft_write_nbr_into_ltrs(char *nbr, char *buffer);
void	ft_convert_full_nbr(char *nbr, char *buffer);
void	ft_write_nbr_2digits(char *nbr, char *buffer);

/*
 *	Open_read.c - Open and read files.
*/

char	*ft_open_read();

#endif
