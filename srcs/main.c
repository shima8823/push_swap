/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:26:41 by shima             #+#    #+#             */
/*   Updated: 2022/08/24 11:49:12 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dclist	*args_to_stack(int argc, char *argv[]);
bool		is_stack_dupulicate(t_dclist *stack);
void		sort(t_dclist **a, t_dclist **b);

int	main(int argc, char *argv[])
{
	t_dclist	*stack_a;
	t_dclist	*stack_b;

	stack_a = args_to_stack(argc, argv);
	stack_b = NULL;
	if (is_stack_dupulicate(stack_a))
		error();
	if (is_stack_sorted(stack_a))
		exit(EXIT_SUCCESS);
	sort(&stack_a, &stack_b);
	exit(EXIT_SUCCESS);
}

t_dclist	*args_to_stack(int argc, char *argv[])
{
	t_dclist	*a;
	t_dclist	*tmp;
	int			size;
	int			i;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	a = NULL;
	size = argc - 1;
	i = 0;
	while (i < size)
	{
		tmp = dclst_new(atoi_for_push_swap(argv[i + 1]));
		if (tmp == NULL)
			exit(EXIT_FAILURE);
		dclst_add_back(&a, tmp);
		i++;
	}
	return (a);
}

bool	is_stack_dupulicate(t_dclist *a)
{
	t_dclist	*b;
	int			size;
	int			i;
	int			j;

	b = a;
	size = dclst_size(a);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i != j && a->value == b->value)
				return (true);
			b = b->next;
			j++;
		}
		a = a->next;
		i++;
	}
	return (false);
}

bool	is_stack_sorted(t_dclist *a)
{
	int	size;
	int	prev_val;
	int	i;

	size = dclst_size(a);
	prev_val = a->value;
	a = a->next;
	i = 1;
	while (i < size)
	{
		if (prev_val >= a->value)
			return (false);
		prev_val = a->value;
		a = a->next;
		i++;
	}
	return (true);
}

void	sort(t_dclist **a, t_dclist **b)
{
	int	size;

	size = dclst_size(*a);
	if (size == 1)
		return ;
	else if (size == 2)
		sa(a);
	else if (size == 3)
		three_sort(a);
	else if (size <= 6)
		six_sort(a, b, size);
	else
		radix_sort(a, b, size);
}

// test
// void	print_stack(t_dclist *stack_a)
// {
// 	int	size;
// 	int	i;
// 	if (!stack_a)
// 		return ;
// 	size = dclst_size(stack_a);
// 		ft_printf("a");
// 	i = 0;
// 	while(i < size)
// 	{
// 		ft_printf("--%d--\nprev: %d\nvalue: %d\nrank: %d\nnext: %d\n", i, st
// ack_a->prev->value, stack_a->value, stack_a->rank, stack_a->next->value);
// 		stack_a = stack_a->next;
// 		i++;
// 	}
// }