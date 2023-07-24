/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusman <yusman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:21:37 by yusman            #+#    #+#             */
/*   Updated: 2022/12/25 15:09:55 by yusman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int n, char c)
{
	int		len;
	char	*hex;

	len = 1;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (c == 'x')
		hex = "0123456789abcdef";
	if (n > 15)
		len += ft_hex(n / 16, c);
	ft_putchar(hex[n % 16]);
	return (len);
}
