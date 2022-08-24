/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:26:39 by shima             #+#    #+#             */
/*   Updated: 2022/08/24 11:35:00 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_dclist
{
	int				value;
	int				rank;
	struct s_dclist	*prev;
	struct s_dclist	*next;
}	t_dclist;

// list.c
t_dclist	*dclst_new(int value);
void		dclst_add_back(t_dclist **lst, t_dclist *new);
t_dclist	*dclst_last(t_dclist *lst);
int			dclst_size(t_dclist *lst);
void		dclst_add_front(t_dclist **lst, t_dclist *new);

// main.c
bool		is_stack_sorted(t_dclist *a);

// swap.c
void		sa(t_dclist **stack);

// rotate.c
void		ra(t_dclist **a);
void		rra(t_dclist **a);

// push.c
void		pa(t_dclist **b, t_dclist **a);
void		pb(t_dclist **a, t_dclist **b);

// radix_sort.c
void		radix_sort(t_dclist **a, t_dclist **b, int size);
void		coordinate_compression(t_dclist **a, int size);
t_dclist	*min_elm_and_no_rank(t_dclist *a, int size);

// other_sort.c
void		three_sort(t_dclist **a);
void		six_sort(t_dclist **a, t_dclist **b, int size);

// utility.c
int			atoi_for_push_swap(const char *str);
void		error(void);

// test
// void		print_stack(t_dclist *stack_a);
#endif