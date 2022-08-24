/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:40:28 by shima             #+#    #+#             */
/*   Updated: 2022/08/24 09:48:54 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_dclist **a, t_dclist **b, int size)
{
	int	max_rank;
	int	max_bit;
	int	i;
	int	j;

	coordinate_compression(a, size);
	max_rank = size - 1;
	max_bit = 0;
	while ((max_rank >> max_bit) != 0)
		max_bit++;
	i = -1;
	while (++i < max_bit)
	{
		j = -1;
		while (++j < size)
		{
			if (((*a)->rank >> i) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (dclst_size(*b) > 0)
			pa(b, a);
	}
}

void	coordinate_compression(t_dclist **a, int size)
{
	t_dclist	*tmp;
	int			i;

	i = 0;
	while (i < size)
	{
		tmp = min_elm_and_no_rank(*a, size);
		tmp->rank = i;
		i++;
	}
}

t_dclist	*min_elm_and_no_rank(t_dclist *a, int size)
{
	t_dclist	*ret;
	int			i;

	ret = NULL;
	i = 0;
	while (i < size)
	{
		if (!ret && a->rank == -1)
			ret = a;
		if (ret && ret->value > a->value && a->rank == -1)
			ret = a;
		a = a->next;
		i++;
	}
	return (ret);
}

// a
//   87 -487  781   10 -100   20  101    0    1  30
//    7    0    9    4    1    5    8    2    3   6
//  111  000 1001  100  001  101 1000  010  011 110

// a
// 7    0    9    4    1    5    8    2    3   6
// b
// 
