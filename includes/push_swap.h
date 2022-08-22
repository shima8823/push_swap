/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:26:39 by shima             #+#    #+#             */
/*   Updated: 2022/08/22 12:40:03 by shima            ###   ########.fr       */
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
	struct s_dclist	*prev;
	struct s_dclist	*next;
}	t_dclist;

// list.c
t_dclist	*dclst_new(int value);
void		dclst_add_back(t_dclist **lst, t_dclist *new);
t_dclist	*dclst_last(t_dclist *lst);
int			dclst_size(t_dclist *lst);

// swap.c
void	sa(t_dclist *stack);

// rotate.c
void	ra(t_dclist **a);

// test
void	print_stack(t_dclist *stack_a);

#endif