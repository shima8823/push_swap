/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:56:35 by shima             #+#    #+#             */
/*   Updated: 2022/08/23 21:00:06 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_min_elm_to_first(t_dclist **a, int size);
int		min_elm_pos(t_dclist *stack, int size);

void	three_sort(t_dclist **a)
{
	if (is_stack_sorted(*a))
		return;
	if ((*a)->value < (*a)->next->value)
	{
		if ((*a)->value < (*a)->next->next->value)
		{
			sa(*a);
			ra(a);
		}
		else
			rra(a);
		return ;
	}
	if ((*a)->next->value < (*a)->next->next->value)
	{
		if ((*a)->value < (*a)->next->next->value)
			sa(*a);
		else
			ra(a);
	}
	else
	{
		sa(*a);
		rra(a);
	}
}

void	six_sort(t_dclist **a, t_dclist **b, int size)
{
	while (size > 3)
	{
		move_min_elm_to_first(a, size);
		pb(a, b);
		size--;
	}
	three_sort(a);
	while (dclst_size(*b) > 0)
		pa(b, a);
}

void	move_min_elm_to_first(t_dclist **a, int size)
{
	int	pos;

	pos = min_elm_pos(*a, size);
	if (pos <= (size / 2) + 1)
		while (--pos)
			ra(a);
	else
		while (pos++ <= size)
			rra(a);
}

int	min_elm_pos(t_dclist *stack, int size)
{
	int			min;
	int			pos;
	int			i;

	min = stack->value;
	i = 1;
	stack = stack->next;
	while (i < size)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
		i++;
	}
	pos = 1;
	i = 0;
	while (i < size)
	{
		if (min == stack->value)
			break ;
		stack = stack->next;
		pos++;
		i++;
	}
	return (pos);
}
