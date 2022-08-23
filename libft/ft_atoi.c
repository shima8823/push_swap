/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:11:29 by shima             #+#    #+#             */
/*   Updated: 2022/08/23 19:36:29 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c);

int	ft_atoi(const char *str)
{
	// size_t			digit;
	// int				sign;
	// unsigned long	num;
	// size_t			i;

	// digit = 0;
	// sign = 1;
	// num = 0;
	// i = 0;
	// if (str[i] == '+' || str[i] == '-')
	// 	if (str[i++] == '-')
	// 		sign = -1;
	// while (str[i] == '0')
	// 	i++;
	// while (ft_isdigit(str[i]))
	// {
	// 	num = num * 10 + str[i++] - '0';
	// 	if (++digit > 19 || num > __LONG_MAX__)
	// 		return ((int)long_overflow(sign));
	// }
	// return ((int)num * sign);
	long	ret;
	int		sign;
	size_t	i;

	ret = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		ret = ret * 10 + str[i++] - '0';
	}
	return (ret);
}

int	ft_isspace(int c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (true);
	return (false);
}
