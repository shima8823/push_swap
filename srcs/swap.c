/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:41:15 by shima             #+#    #+#             */
/*   Updated: 2022/08/23 15:48:32 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_dclist *stack)
{
	int tmp;

	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	ft_printf("sa\n");
}
