/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shima <shima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 10:15:45 by shima             #+#    #+#             */
/*   Updated: 2022/08/20 10:49:17 by shima            ###   ########.fr       */
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
		*lst = new;
		return ;
	}
	last = dclst_last(*lst);
	last->next = new;
	new->prev = last;
	new->next = (*lst);
	(*lst)->prev = new;
}

t_dclist	*dclst_last(t_dclist *lst)
{
	if (lst)
		if (lst->prev)
			return (lst->prev);
	return (lst);
}
