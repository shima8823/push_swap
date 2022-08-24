/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 18:13:34 by shima             #+#    #+#             */
/*   Updated: 2022/08/24 11:32:44 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_isspace(int c);

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
	if (!str[i])
		error();
	while (str[i] == '0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error();
		ret = ret * 10 + str[i++] - '0';
		if (ret * sign < INT_MIN || INT_MAX < ret * sign)
			error();
	}
	return (ret * sign);
}

int	ft_isspace(int c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (true);
	return (false);
}

void	error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
