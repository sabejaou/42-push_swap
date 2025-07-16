/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:00:01 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/14 03:05:17 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_max(t_lst *alst)
{
	int		max;
	t_lst	*current;

	max = alst->nb;
	current = alst->next;
	while (current != alst)
	{
		if (current->nb > max)
			max = current->nb;
		current = current->next;
	}
	return (max);
}

void	ft_reindex(t_lst **alst, size_t nbelems)
{
	int		i;
	t_lst	*smaller;
	t_lst	*node;

	i = 0;
	while (i <= (int)nbelems && *alst && nbelems)
	{
		node = *alst;
		smaller = *alst;
		while (smaller->index >= 0)
		{
			smaller = smaller->next;
			node = node->next;
		}
		while (node->next != *alst)
		{
			if (node->nb < smaller->nb && node->index < 0)
				smaller = node;
			node = node->next;
		}
		if (node->nb < smaller->nb && node->index < 0)
			smaller = node;
		smaller->index = i++;
	}
}

int	ft_error(int fd, t_stack *stack, int ac)
{
	if (ac >= 2)
		ft_printf(fd, "Error\n");
	if (stack && stack->alst)
		ft_lstcirc_clear(&stack->alst);
	if (stack)
		free(stack);
	return (-1);
}

int	ft_end(t_stack *stack)
{
	ft_lstcirc_clear(&(stack->alst));
	free(stack);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack;

	i = 1;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (ft_error(2, NULL, ac));
	stack->alst = NULL;
	if (ac <= 1 || ft_check_args(av))
		return (ft_error(2, stack, ac));
	(stack->alst) = ft_arg_to_lst(av[i++], &stack);
	stack->blst = NULL;
	while (av[i] && (stack->alst))
		(stack->alst) = ft_arg_to_lst(av[i++], &stack);
	stack->nbelems = ft_lstcirc_size(stack->alst) - 1;
	ft_reindex(&stack->alst, stack->nbelems);
	if ((stack->alst) == NULL || is_double(stack->alst))
		return (ft_error(2, stack, ac));
	if (is_sorted(stack))
		return (ft_end(stack));
	if (stack->nbelems <= 4)
		ft_littlesort(stack);
	else
		ft_sort(stack);
	return (ft_end(stack));
}
