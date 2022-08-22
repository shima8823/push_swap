/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:26:41 by shima             #+#    #+#             */
/*   Updated: 2022/08/22 12:51:38 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dclist	*arg_to_stack(int argc, char *argv[]);
bool	is_stack_sorted(t_dclist *a);
void	sort(t_dclist **a);
void	three_sort(t_dclist **a);

int	main(int argc, char *argv[])
{
	t_dclist	*stack_a;
	stack_a = arg_to_stack(argc, argv);

// unit test
	// print_stack(stack_a);
	// printf("\nsize\n%d\n", dclst_size(stack_a));
	// if (is_stack_sorted(stack_a))
	// 	printf("true\n");
	// else
	// 	printf("false\n");
//
	//leak あり
	if (is_stack_sorted(stack_a))
		return (EXIT_SUCCESS);
	// sort
	sort(&stack_a);
	print_stack(stack_a);

	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

t_dclist	*arg_to_stack(int argc, char *argv[])
{
	t_dclist	*stack_a;
	t_dclist	*tmp;
	int			size;
	int			i;

	if (argc <= 1)
		exit(EXIT_FAILURE);
	size = argc - 1;
	i = 1;
	stack_a = dclst_new(ft_atoi(argv[i]));
	if (stack_a == NULL)
		exit(EXIT_FAILURE);
	while (i < size)
	{
		// ft_printf("%s", argv[i + 1]);
		tmp = dclst_new(ft_atoi(argv[i + 1]));
		dclst_add_back(&stack_a, tmp);
		i++;
	}
	return (stack_a);
}

bool	is_stack_sorted(t_dclist *a)
{
	t_dclist *start_p;
	int	prev_val;

	start_p = a;
	prev_val = a->value;
	a = a->next;
	while (a)
	{
		if (start_p == a)
			break;
		if (prev_val >= a->value)
			return (false);
		prev_val = a->value;
		a = a->next;
	}
	return (true);
}

void	sort(t_dclist **a)
{
	int size;

	size = dclst_size(*a);
	if (size == 1)
		return ;
	else if (size == 2)
		sa(*a);
	else if (size == 3)
		three_sort(a);
	// ft_printf("afterfunc2 a: %p\n", a);
}

void	three_sort(t_dclist **a)
{
	if ((*a)->value < (*a)->next->value)
	{
		if ((*a)->value < (*a)->next->next->value)
		{
			sa(*a);
			ra(a);
		}
		else
			ft_printf("rra\n");
	}
	else
	{
		if ((*a)->next->value < (*a)->next->next->value)
		{
			if ((*a)->value < (*a)->next->next->value)
				ft_printf("sa\n");
			else
				ft_printf("ra\n");
		}
		else
			ft_printf("sa, rra\n");
	}
	// 1 < 3 > 2 <			sa 3 1 2 ra 1 2 3 
	// 2 < 3 > 1 >			rra
	// 2 > 1 < 3 <			sa
	// 3 > 1 < 2 >			ra
	// 3 > 2 > 1 >			sa 2 3 1 rra 123
}

bool	is_num_unique(t_dclist a, int size)
{
	int	i;

	i = 0;
	// while (i < size)
	// {
		
	// }
	return (true);
}

// test

void	print_stack(t_dclist *stack_a)
{
	int	start_val;
	int i;

	start_val = stack_a->value;
	i = 1;
	// printf("%s, %d\n", __FILE__, __LINE__);
	while(true)
	{
		if (i != 1 && stack_a->value == start_val)
			break;
		if (!stack_a->next)
		{
			ft_printf("--1個しかない--\nvalue: %d\n", stack_a->value);
			break ;
		}
		ft_printf("--%d--\nprev: %d\nvalue: %d\nnext: %d\n", i, stack_a->prev->value, stack_a->value, stack_a->next->value);
		stack_a = stack_a->next;
		i++;
	}
}
