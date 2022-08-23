/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:13:34 by shima             #+#    #+#             */
/*   Updated: 2022/08/23 19:58:05 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isspace(int c);
void error2();


int	atoi_for_push_swap(const char *str)
{
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
			error2();
		ret = ret * 10 + str[i++] - '0';
		if (ret < INT_MIN || INT_MAX < ret)
			error2();
	}
	return (ret * sign);
}

int	ft_isspace(int c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (true);
	return (false);
}

void error2()
{
	ft_printf("Error2\n");
	exit(EXIT_FAILURE);
}

void error()
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
