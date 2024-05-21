/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:45:47 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/21 12:10:05 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort(va_list args, char format)
{
	if (format == 'c')
		return (ft_print_c(va_arg(args, int)));
	else if (format == 's')
		return (ft_print_s(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(args, unsigned long)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_nbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_print_c('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	int		args_count;
	va_list	args;

	i = 0;
	count = 0;
	args_count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_print_c(format[i]);
		else
		{
			i++;
			count = count + ft_sort(args, format[i]);
			args_count++;
		}
		i++;
	}
	va_end(args);
	return (count + i - (args_count * 2));
}
/* 
int	main(void)
{
	printf("C: %i\n", ft_printf(" %p ", 16));
	printf("CP: %i \n", printf(" %p ", 16));
	printf("C: %i\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));
	printf("CP: %i \n", printf(" %p %p ", LONG_MIN, LONG_MAX));
	printf("C: %i\n", ft_printf(" %p %p ", INT_MIN, INT_MAX));
	printf("CP: %i \n", printf(" %p %p ", INT_MIN, INT_MAX));
	printf("C: %i\n", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	printf("CP: %i \n", printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	return (0);
} */
