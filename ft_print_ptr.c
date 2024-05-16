/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:16:43 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/16 17:29:59 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checklen_hexa(long n)
{
	int	counter;

	counter = 1;
	if (n == LONG_MIN)
		counter = 16;
	else
	{
		while (n >= 16)
		{
			n = n / 16;
			counter++;
		}
	}
	return (counter);
}

char	*ft_address(long nb)
{
	char	*address;
	char	*hexa;
	int		i;
	int		len;
	int temp;

	i = 0;
	len = ft_checklen_hexa(nb) + 2;
	temp = 0;
	hexa = ft_strdup("0123456789abcdef");
	address = (char *)malloc((len + 1) * sizeof(char));
	address[0] = '0';
	address[1] = 'x';
	while (nb != 0)
	{
		temp = nb % 16;
		if (temp < 0)
			temp = temp + 16;
		address[len - i - 1] = hexa[temp];
		nb /= 16;
		i++;
	}
	address[len] = '\0';
	free(hexa);
	return (address);
}

int	ft_free(long nb, char *(*f)(long nb))
{
	int		ret;
	char	*str;

	str = f(nb);
	ret = ft_print_s(str);
	free(str);
	return (ret);
}

int	ft_print_ptr(void *p)
{
	long	address;

	if (!p)
		return (0);
	address = (long)p;
	return (ft_free(address, ft_address));
}
