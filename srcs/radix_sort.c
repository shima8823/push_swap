/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:40:28 by shima             #+#    #+#             */
/*   Updated: 2022/08/23 16:43:43 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_dclist **a, t_dclist **b, int size)
{
	// a
	//   87 -487  781   10 -100   20  101    0    1  30
	//    7    0    9    4    1    5    8    2    3   6
	//  111  000 1001  100  001  101 1000  010  011 110

	// a
	// 7    0    9    4    1    5    8    2    3   6
	// b
	// 
	int	max_rank;
	int max_bits;
	int	i;
	int	j;
	// print_stack(*a);
	coordinate_compression(a);
	// print_stack(*a);
	size = dclst_size(*a);
	max_rank = size - 1; // 9 1001
	max_bits = 0; // 4
	while ((max_rank >> max_bits) != 0)
		max_bits++;
	// // max_bits 3
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while(j < size)
		{
			if (((((*a)->rank) >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (dclst_size(*b) > 0)
			pa(b, a);
		i++;
	}
}

void	coordinate_compression(t_dclist **a)
{
	t_dclist	*tmp;
	int	size;
	int	i;

	size = dclst_size(*a);
	i = 0;
	while (i < size)
	{
		// 小さい && rank == -1 t_dclistで返してもらう
		tmp = min_elm_and_no_rank(*a);
		// ft_printf("tmp->value: %d\n", tmp->value);
		tmp->rank = i;
		i++;
	}
}

t_dclist	*min_elm_and_no_rank(t_dclist *a)
{
	t_dclist	*start_p;
	t_dclist	*ret;
	bool		isfirst;

	while (true)
	{
		if (a->rank == -1)
		{
			ret = a;
			break ;
		}
		a = a->next;
	}
	start_p = a;
	isfirst = true;
	while (true)
	{
		if (!isfirst && start_p == a)
			break ;
		if (ret->value > a->value && a->rank == -1)
			ret = a;
		isfirst = false;
		a = a->next;
	}
	return (ret);
}
