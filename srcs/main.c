/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:26:41 by shima             #+#    #+#             */
/*   Updated: 2022/08/20 10:57:46 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dclist	*arg_to_stack(int argc, char *argv[]);

// test
void	print_stack(t_dclist *stack_a);

int	main(int argc, char *argv[])
{
	t_dclist	*stack_a;
	stack_a = arg_to_stack(argc, argv);
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
