/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:10:45 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/14 22:34:47 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_lst **a, t_lst **b, char abr)
{
	if (abr == 'a' || abr == 'r')
		*a = (*a)->next;
	if (abr == 'b' || abr == 'r')
		*b = (*b)->next;
	ft_printf(1, "r%c\n", abr);
}

void	reverse_rotate(t_lst **a, t_lst **b, char abr)
{
	if (abr == 'a' || abr == 'r')
		*a = (*a)->prev;
	if (abr == 'b' || abr == 'r')
		*b = (*b)->prev;
	ft_printf(1, "rr%c\n", abr);
}

void	push(t_lst **fromlst, t_lst **tolst, char ab)
{
	t_lst	*node;

	node = *fromlst;
	if (node->next == node)
		*fromlst = NULL;
	if (node->next != node)
	{
		(*fromlst)->prev->next = (*fromlst)->next;
		(*fromlst)->next->prev = (*fromlst)->prev;
		*fromlst = (*fromlst)->next;
	}
	node->next = node;
	node->prev = node;
	*tolst = ft_lstcirc_addf(tolst, node);
	ft_printf(1, "p%c\n", ab);
}

void	swap(t_lst **a, t_lst **b, char abs)
{
	t_lst	*tnode;

	if (abs == 'a' || abs == 's')
	{
		tnode = (*a)->next;
		(*a)->next = tnode->next;
		tnode->next->prev = *a;
		tnode->prev = (*a)->prev;
		(*a)->prev->next = tnode;
		(*a)->prev = tnode;
		tnode->next = *a;
		*a = tnode;
	}
	if (abs == 'b' || abs == 's')
	{
		tnode = (*b)->next->next;
		(*b)->prev->next = (*b)->next;
		(*b)->next->prev = (*b)->prev;
		(*b)->prev = (*b)->next;
		(*b)->next->next = (*b);
		(*b)->next = tnode;
		*b = tnode;
	}
	ft_printf(1, "s%c\n", abs);
}
