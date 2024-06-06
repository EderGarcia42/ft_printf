/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:03:24 by edegarci          #+#    #+#             */
/*   Updated: 2024/06/06 15:16:34 by edegarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_var(char c, va_list data)
{
	if (c == 'c')
		return (ft_putchar(va_arg(data, int)));
	if (c == 's')
		return (ft_putstr(va_arg(data, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(data, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(data, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(data, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_base(va_arg(data, unsigned int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_putnbr_base(va_arg(data, unsigned int), "0123456789ABCDEF"));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (*(str + i))
	{
		if (*(str + i) == '%' && ft_strchr("cspdiuxX%", *(str + i + 1)))
		{
			len += ft_format(args, *(str + i + 1));
			i++;
		}
		else
			len += ft_putchar(*(str + i));
		i++;
	}
	va_end(args);
	return (len);
}

/* int	main(void)
{
	char			c = 'A';
	char			*str = '\0';
	void			*ptr = '\0';
	int				d = 777;
	int				i = -777;
	unsigned int	u = -7777;
	unsigned int	x = 255;
	unsigned int	X = 255;

	// Caracteres individuales
	printf("%d\n", ft_printf("Caracter: %c\n", c));
	printf("%d\n", printf("Caracter: %c\n", c));
	// Cadenas
	printf("%d\n", ft_printf("Cadena: %s\n", str));
	printf("%d\n", printf("Cadena: %s\n", str));
	// Punteros
	printf("%d\n", ft_printf("Puntero: %p\n", ptr));
	printf("%d\n", printf("Puntero: %p\n", ptr));
	// Enteros
	printf("%d\n", ft_printf("Entero (d): %d\n", d));
	printf("%d\n", ft_printf("Entero (i): %i\n", i));
	printf("%d\n", printf("Entero (d): %d\n", d));
	printf("%d\n", printf("Entero (i): %i\n", i));
	// Enteros sin signo
	printf("%d\n", ft_printf("Entero sin signo: %u\n", u));
	printf("%d\n", printf("Entero sin signo: %u\n", u));
	// Enteros hexadecimales
	printf("%d\n", ft_printf("Hexadecimal (x): %x\n", x));
	printf("%d\n", ft_printf("Hexadecimal en mayúsculas (X): %X\n", X));
	printf("%d\n", printf("Hexadecimal (x): %x\n", x));
	printf("%d\n", printf("Hexadecimal en mayúsculas (X): %X\n", X));
	// Símbolo de porcentaje
	printf("%d\n", ft_printf("Porcentaje: %%\n"));
	printf("%d\n", printf("Porcentaje: %%\n"));
	return (0);
} */