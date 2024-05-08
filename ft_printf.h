/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:41:59 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/08 17:44:39 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_printf_c(int c);
int		ft_printf_s(char *s);
int		ft_printf_p(void *p);
int		ft_printf_i(int i);
int		ft_printf_u(unsigned long i);
int		ft_printf_x(unsigned int x);
int		ft_printf_xx(unsigned int x);
int		ft_printf_z(int c);
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, int n);
char	*ft_itoa(int n);