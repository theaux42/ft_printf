/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 07:47:07 by tbabou            #+#    #+#             */
/*   Updated: 2024/01/17 22:07:58 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		j;

	j = ft_intlen(n) - 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[j + 1] = '\0';
	while (n)
	{
		str[j] = n % 10 + 48;
		n = n / 10;
		j--;
	}
	return (str);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		j;

	j = ft_uintlen(n) - 1;
	str = (char *)malloc(sizeof(char) * (ft_uintlen(n) + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	str[j + 1] = '\0';
	while (n)
	{
		str[j] = n % 10 + 48;
		n = n / 10;
		j--;
	}
	return (str);
}

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

int	ft_putunbr(unsigned int n)
{
	int		len;
	char	*str;

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
