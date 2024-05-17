/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:45:47 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/17 13:01:30 by jalombar         ###   ########.fr       */
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
		return (ft_print_ptr(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_print_nbr(va_arg(args, unsigned int)));
	else if (format == 'x')
		return (ft_print_x(va_arg(args, unsigned int), 'x'));
	else if (format == 'X')
		return (ft_print_x(va_arg(args, unsigned int), 'X'));
	else if (format == '%')
		return (ft_print_c('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	int		temp;
	int		args_count;
	va_list	args;

	i = 0;
	count = 0;
	temp = 0;
	args_count = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_print_c(format[i]);
		else
		{
			i++;
			temp = ft_sort(args, format[i]);
			args_count++;
			count = count + temp;
		}
		i++;
	}
	va_end(args);
	return (count + i - (args_count * 2));
}

/* int	main(void)
{
	printf("C: %i\n", ft_printf(" %u ", ULONG_MAX));
	printf("CP: %i \n", printf(" %u ", ULONG_MAX));
	printf("C: %i\n", ft_printf(" %u ", 9223372036854775807LL));
	printf("CP: %i \n", printf(" %u ", 9223372036854775807LL));
	return (0);
} */
