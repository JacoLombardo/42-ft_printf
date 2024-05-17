/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:25:41 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/17 12:25:21 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		free(s);
		return (ft_print_s("(null)"));
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_hexa(long nb, char *base)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc((ft_checklen(nb) + 1) * sizeof(char));
	while (nb != 0)
	{
		str[i] = base[nb % 16];
		nb /= 16;
		i++;
	}
	str[i] = '\0';
	free(base);
	return (str);
}

int	ft_print_x(long nb, char type)
{
	char	*base;
	int		ret;
	char	*str;

	if (nb == 0)
	{
		return (ft_print_c('0'));
	}
	else
	{
		if (type == 'x')
			base = ft_strdup("0123456789abcdef");
		else
			base = ft_strdup("0123456789ABCDEF");
		str = ft_hexa(nb, base);
		ft_reverse(str);
		ret = ft_print_s(str);
		free(str);
		return (ret);
	}
}
