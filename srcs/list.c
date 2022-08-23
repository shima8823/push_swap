/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:15:45 by shima             #+#    #+#             */
/*   Updated: 2022/08/23 19:24:33 by shima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dclist	*dclst_new(int value)
{
	t_dclist	*new;

	new = malloc(sizeof(t_dclist));
	if (!new)
		return (NULL);
	(*new).value = value;
	(*new).rank = -1;
	(*new).prev = NULL;
	(*new).next = NULL;
	return (new);
}

void	dclst_add_back(t_dclist **lst, t_dclist *new)
{
	t_dclist	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		new->next = NULL;
		new->prev = NULL;
		*lst = new;
		return ;
	}
	last = dclst_last(*lst);
	last->next = new;
	new->prev = last;
	new->next = (*lst);
	(*lst)->prev = new;
}

void	dclst_add_front(t_dclist **lst, t_dclist *new)
{
	t_dclist	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		new->prev = NULL;
		new->next = NULL;
		*lst = new;
		return ;
	}
	last = dclst_last(*lst);
	new->prev = last;
	new->next = *lst;
	(*lst)->prev = new;
	last->next = new;
	*lst = new;
}

t_dclist	*dclst_last(t_dclist *lst)
{
	if (lst)
		if (lst->prev)
			return (lst->prev);
	return (lst);
}

int	dclst_size(t_dclist *lst)
{
	int			size;
	t_dclist	*start_p;

	if (!lst)
		return (0);
	size = 0;
	start_p = lst;
	while (lst)
	{
		if (size > 0 && start_p == lst)
			break ;
		size++;
		lst = lst->next;
	}
	return (size);
}
