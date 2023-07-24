/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:24:51 by yusman            #+#    #+#             */
/*   Updated: 2022/12/25 15:09:36 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(unsigned long n)
{
	int	len;

	len = ft_putstr("0x");
	if (n == 0)
		len += ft_putchar('0');
	else
		len += ft_hex_p(n);
	return (len);
}

int	ft_hex_p(unsigned long n)
{
	int		len;
	char	*hex;

	len = 1;
	hex = "0123456789abcdef";
	if (n > 15)
		len += ft_hex_p(n / 16);
	ft_putchar(hex[n % 16]);
	return (len);
}
