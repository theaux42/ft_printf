/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 06:54:26 by tbabou            #+#    #+#             */
/*   Updated: 2023/12/01 15:04:21 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	variable_manager(char c, va_list arguments)
{
	int	added;

	added = 0;
	if (c == 's')
		added += ft_putstr(va_arg(arguments, char *));
	else if (c == 'c')
		added += ft_putchar((unsigned char)va_arg(arguments, int));
	else if (c == 'x')
		added += ft_puthexa(va_arg(arguments, int), 0);
	else if (c == 'X')
		added += ft_puthexa(va_arg(arguments, int), 1);
	else if (c == '%')
		added += ft_putchar('%');
	else if (c == 'p')
		added += ft_putptr((unsigned long long)va_arg(arguments, void *));
	else if (c == 'u')
		added += ft_putunbr(va_arg(arguments, unsigned int));
	else if (c == 'i' || c == 'd')
		added += ft_putnbr(va_arg(arguments, int));
	return (added);
}

int	output_manager(char *str, va_list arguments)
{
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			printed += variable_manager(str[i], arguments);
		}
		else
		{
			ft_putchar(str[i]);
			printed++;
		}
		i++;
	}
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	int		printed;
	va_list	args;

	printed = 0;
	va_start(args, format);
	printed += output_manager((char *)format, args);
	va_end(args);
	return (printed);
}
