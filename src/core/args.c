/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:03:17 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/14 03:05:50 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_skip_sp_nb(char *av)
{
	int	j;

	j = 0;
	while (av[j] && (av[j] == ' ' || (av[j] >= 9 && av[j] <= 13)))
		j++;
	if ((av[j] == '+' || av[j] == '-'))
		j++;
	while (av[j] >= '0' && av[j] <= '9')
		j++;
	while (av[j] && (av[j] == ' ' || (av[j] >= 9 && av[j] <= 13)))
		j++;
	return (j);
}

t_lst	*ft_arg_to_lst(char *arg, t_stack **stack)
{
	int	i;

	i = 0;
	if (!arg)
		return ((*stack)->alst);
	while (arg[i])
	{
		(*stack)->alst = ft_lstcirc_addb(&((*stack)->alst),
				ft_lstcirc_new(ft_atoi(arg + i)));
		if (!(*stack)->alst)
			return (NULL);
		i += ft_skip_sp_nb(arg + i);
		if ((arg[i] == '+' || arg[i] == '-') && !(arg[i - 1] == ' '
				|| (arg[i - 1] >= 9 && arg[i - 1] <= 13)))
		{
			ft_lstcirc_clear(&(*stack)->alst);
			return (NULL);
		}
	}
	return ((*stack)->alst);
}

int	ft_check_args(char **av)
{
	int	i;
	int	j;
	int	digit;

	i = 0;
	j = 0;
	while (av[++i])
	{
		digit = 0;
		while (av[i][j])
		{
			if ((av[i][j] != '+' && av[i][j] != '-' && av[i][j] != ' '
				&& (av[i][j] < 9 || av[i][j] > 13) && (av[i][j] < '0'
				|| av[i][j] > '9')) || (((av[i][j] == '+'
				|| av[i][j] == '-') && !av[i][j + 1])))
				return (1);
			if ((av[i][j] >= '0' && av[i][j] <= '9'))
				digit++;
			j++;
		}
		j = 0;
	}
	if (!digit)
		return (1);
	return (0);
}

int	is_double(t_lst *a)
{
	t_lst	*current;
	t_lst	*cmp;

	current = a;
	cmp = a->next;
	while (cmp != a)
	{
		if (current->nb == cmp->nb || current->nb > 2147483647
			|| current->nb < -2147483648)
			return (1);
		current = current->next;
		cmp = current->next;
	}
	if ((current->nb == cmp->nb || current->nb > 2147483647
			|| current->nb < -2147483648) && (current != cmp
			|| (current->nb > 2147483647 || current->nb < -2147483648)))
		return (1);
	return (0);
}
