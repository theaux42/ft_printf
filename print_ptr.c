/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:33:51 by tbabou            #+#    #+#             */
/*   Updated: 2023/12/01 14:06:34 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_printptr(num / 16);
		ft_printptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += ft_putstr("0x");
	if (ptr == 0)
		print_length += ft_putchar('0');
	else
	{
		ft_printptr(ptr);
		print_length += ft_hexalen(ptr);
	}
	return (print_length);
}
