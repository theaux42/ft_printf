/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 07:47:07 by tbabou            #+#    #+#             */
/*   Updated: 2023/12/01 14:06:34 by tbabou           ###   ########.fr       */
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
