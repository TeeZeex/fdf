/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:42:44 by yusman            #+#    #+#             */
/*   Updated: 2022/12/25 14:52:48 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharv(char c)
{
	write(1, &c, 1);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 1;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		len++;
		n = n * -1;
	}
	if (n > 9)
	{
		len += ft_putnbr(n / 10);
	}
	ft_putcharv((n % 10) + '0');
	return (len);
}
