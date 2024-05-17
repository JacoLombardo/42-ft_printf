/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:43:16 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/17 15:44:42 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reverse(char *str)
{
	char	temp;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

void	ft_breaknbr(long n, char *str, int i)
{
	if (n >= 10)
	{
		ft_breaknbr((n / 10), str, i + 1);
		ft_breaknbr((n % 10), str, i);
	}
	else
		str[i] = n + '0';
}

int	ft_checklen(long n)
{
	int	counter;

	counter = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		counter++;
	}
	while (n >= 10)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(long n)
{
	char	*str;
	int		len;
	int		negative;

	negative = 0;
	len = ft_checklen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	ft_breaknbr(n, str, 0);
	if (negative)
		str[len - 1] = '-';
	str[len] = '\0';
	ft_reverse(str);
	return (str);
}
