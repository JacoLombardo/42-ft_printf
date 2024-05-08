/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:45:47 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/08 17:42:06 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort(va_list args, char format)
{
	if (format == 'c')
		return (ft_printf_c(va_arg(args, int)));
	else if (format == 's')
		return (ft_printf_s(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_printf_p(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_printf_i(va_arg(args, int)));
	else if (format == 'u')
		return (ft_printf_u(va_arg(args, unsigned long)));
	else if (format == 'x')
		return (ft_printf_x(va_arg(args, unsigned int)));
	else if (format == 'X')
		return (ft_printf_xx(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_printf_z(va_arg(args, int)));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	int		temp;
	va_list	args;

	i = 0;
	count = 0;
	temp = 0;
	if (!format)
		return (0);
	va_start(args, format);
	printf("%s\n", "here");
	while (format[i])
	{
		if (format[i] != '%')
			ft_printf_c(format[i]);
		else
		{
			i++;
			temp = ft_sort(args, format[i]);
			if (!temp)
			{
				ft_printf_c(format[i - 1]);
				ft_printf_c(format[i]);
				count = count + 2;
			}
			else
				count = count + temp;
		}
		i++;
	}
	va_end(args);
	write(1, "\n", 1);
	return (count + i - 1);
}
