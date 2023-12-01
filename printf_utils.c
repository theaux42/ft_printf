/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbabou <tbabou@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:30:29 by tbabou            #+#    #+#             */
/*   Updated: 2023/12/01 14:06:34 by tbabou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(ft_strlen((char *)s1) + 1);
	if (!tmp)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

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

int	ft_hexalen(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

int	ft_intlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr < 1)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
