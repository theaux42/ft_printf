/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:43:05 by tbabou            #+#    #+#             */
/*   Updated: 2023/11/30 23:35:07 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	ft_printhexa(unsigned int num, int isUpper)
{
	char	*charlist;

	if (isUpper)
		charlist = "0123456789ABCDEF";
	else
		charlist = "0123456789abcdef";
	if (num >= 16)
	{
		ft_printhexa(num / 16, isUpper);
		ft_printhexa(num % 16, isUpper);
	}
	else if (num <= 9)
		ft_putchar(num + '0');
	else
		ft_putchar(charlist[num]);
}

int	ft_puthexa(unsigned int num, int isUpper)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_printhexa(num, isUpper);
	return (ft_hexalen(num));
}
