/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 07:47:07 by tbabou            #+#    #+#             */
/*   Updated: 2023/12/01 15:14:49 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putnbr(int nb)
{
	char	*str;
	int		len;

	len = 0;
	str = ft_itoa(nb);
	while (str[len])
		len++;
	ft_putstr(str);
	free(str);
	return (len);
}

// int	ft_putunbr(unsigned int nb)
// {
// 	char	*str;
// 	int		len;

// 	len = 0;
// 	str = ft_uitoa(nb);
// 	while (str[len])
// 		len++;
// 	ft_putstr(str);
// 	free(str);
// 	return (len);
// }

int	ft_putunbr(unsigned int n)
{
	int len;
	char *str;

	len = 0;
	if (n == 0)
		len += ft_putchar('0');
	else
	{
		str = ft_uitoa(n);
		len += ft_putstr(str);
		free(str);
	}
	return (len);
}