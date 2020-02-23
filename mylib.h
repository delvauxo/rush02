/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odelvaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 17:25:44 by odelvaux          #+#    #+#             */
/*   Updated: 2020/02/23 23:02:07 by odelvaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *dest, char *src);
char	*ft_strstr(char *nbr, char *to_find);
int		ft_iterative_power(int nb, int power);
int		ft_len(long nb);
char	*ft_itoa(int nb);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_write_nbr_into_ltrs(char *nbr, char *buffer);
void	ft_convert_full_nbr(char *nbr, char *buffer);
void	ft_write_nbr_2digits(char *nbr, char *buffer);
char	*ft_open_read_argv(char *dico);
char	*ft_open_read_default();
int		ft_check_number(char *nbr);
void	ft_write_number_power(int size, char *buffer);

#endif
