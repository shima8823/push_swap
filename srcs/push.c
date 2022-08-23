/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:15:11 by shima             #+#    #+#             */
/*   Updated: 2022/08/23 19:25:36 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_dclist **a, t_dclist **b)
{
	t_dclist	*tmp;

	if (!a || !(*a))
		return ;
	tmp = *a;
	if (dclst_size(*a) == 1)
	{
		*a = NULL;
	}
	else
	{
		(*a)->prev->next = (*a)->next;
		(*a)->next->prev = (*a)->prev;
		*a = (*a)->next;
	}
	dclst_add_front(b, tmp);
}

void	pa(t_dclist **b, t_dclist **a)
{
	ft_printf("pa\n");
	push(b, a);
}

void	pb(t_dclist **a, t_dclist **b)
{
	ft_printf("pb\n");
	push(a, b);
}
