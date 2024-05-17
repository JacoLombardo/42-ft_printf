/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalombar <jalombar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:41:59 by jalombar          #+#    #+#             */
/*   Updated: 2024/05/17 12:57:50 by jalombar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_c(char c);
int		ft_print_s(char *s);
int		ft_print_ptr(void *p);
int		ft_print_nbr(long nb);
int		ft_print_x(long nb, char type);
int		ft_strlen(const char *s);
char	*ft_itoa(long n);
int		ft_checklen(long n);
char	*ft_strdup(const char *s);
int		ft_free(long nb, char *(*f)(long nb));
void	ft_reverse(char *str);