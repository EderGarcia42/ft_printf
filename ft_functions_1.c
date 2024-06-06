/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:27:51 by edegarci          #+#    #+#             */
/*   Updated: 2024/06/06 14:01:54 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list data, char c)
{
	int	len;

	len = 0;
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		len += type_var(c, data);
	return (len);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_base(unsigned long n, char *base)
{
	int				len;
	unsigned int	base_len;

	len = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (n >= base_len)
		len += ft_putnbr_base(n / base_len, base);
	len += ft_putchar(base[n % base_len]);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_unsigned(n / 10);
	c = (n % 10) + '0';
	len += ft_putchar(c);
	return (len);
}
