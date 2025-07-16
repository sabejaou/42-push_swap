/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabejaou <sabejaou@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:23:40 by sabejaou          #+#    #+#             */
/*   Updated: 2024/03/13 16:55:26 by sabejaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

void	ft_printf_secargs(char c, va_list *lst, unsigned int *ct, int fd)
{
	if (c == 'u')
		ft_putnbr_ul_fd(va_arg(*lst, unsigned int), fd, ct);
	if (c == 'x')
		ft_putadd_fd(va_arg(*lst, long), fd, "0123456789abcdef", ct);
	if (c == 'X')
		ft_putadd_fd(va_arg(*lst, long), fd, "0123456789ABCDEF", ct);
	if (c == '%')
		ft_putchar('%', fd, ct);
}

void	ft_print_arg(char c, va_list *lst, unsigned int *ct, int fd)
{
	size_t	add;

	if (c == 'c')
		ft_putchar(va_arg(*lst, int), fd, ct);
	if (c == 's')
		ft_putstr_fd(va_arg(*lst, char *), fd, ct);
	if (c == 'p')
	{
		add = va_arg(*lst, size_t);
		if (add)
		{
			ft_putstr_fd("0x", fd, ct);
			ft_putadd_ul_fd(add, fd, "0123456789abcdef", ct);
		}
		else
			ft_putstr_fd("(nil)", fd, ct);
	}
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(*lst, int), fd, ct);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		ft_printf_secargs(c, lst, ct, fd);
}

int	ft_printf(int fd, const char *fmt, ...)
{
	va_list			lst;
	unsigned int	ct;

	ct = 0;
	if (!fmt)
		return (ct);
	va_start(lst, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			ft_print_arg(*fmt, &lst, &ct, fd);
			fmt++;
		}
		else
		{
			ft_putchar(*fmt, fd, &ct);
			fmt++;
		}
	}
	return (ct);
}
