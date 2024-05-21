/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:41:59 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/21 15:18:43 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_c(char c);
int		ft_print_s(char *s);
int		ft_print_ptr(unsigned long p);
int		ft_print_nbr(long nb);
int		ft_putnbr_base(unsigned long nb, char *base);