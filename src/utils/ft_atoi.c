/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:51:57 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/13 23:12:55 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atoi(char *str)
{
	long int	sign;
	long int	cti;
	long int	i;

	i = 0;
	sign = 1;
	cti = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		cti = cti * 10 + str[i] - 48;
		i++;
	}
	return (cti * sign);
}
