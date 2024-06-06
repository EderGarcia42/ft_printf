/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegarci <edegarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:03:24 by edegarci          #+#    #+#             */
/*   Updated: 2024/06/06 13:02:09 by edegarci         ###   ########.fr       */
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
	char			*str = "Esta vez funcionará!";
	void			*ptr = &c;
	int				d = 777;
	int				i = -777;
	unsigned int	u = 7777;
	unsigned int	x = 255;
	unsigned int	X = 255;
	// Prueba de caracteres individuales
	ft_printf("Caracter: %c\n", c);
	// Prueba de cadenas
	ft_printf("Cadena: %s\n", str);
	// Prueba de punteros
	ft_printf("Puntero: %p\n", ptr);
	// Prueba de enteros
	ft_printf("Entero (d): %d\n", d);
	ft_printf("Entero (i): %i\n", i);
	// Prueba de enteros sin signo
	ft_printf("Entero sin signo: %u\n", u);
	// Prueba de enteros hexadecimales
	ft_printf("Hexadecimal (x): %x\n", x);
	ft_printf("Hexadecimal en mayúsculas (X): %X\n", X);
	// Prueba del símbolo de porcentaje
	ft_printf("Porcentaje: %%\n");
	return (0);
} */