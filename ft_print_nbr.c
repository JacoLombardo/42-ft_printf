/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:04:57 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/16 16:06:58 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(long nb)
{
	if (nb == LONG_MAX || nb == 4294967295)
	{
		printf("%s", "ciao");
		return (ft_free(4294967295, ft_itoa));
	}
	else if (nb == LONG_MIN)
		return (ft_free(0, ft_itoa));
	else
		return (ft_free(nb, ft_itoa));
}
