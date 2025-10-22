/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:30:23 by asharafe          #+#    #+#             */
/*   Updated: 2025/09/20 21:26:46 by asharafe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// #include <stddef.h>

// int	main(void)
// {
// 	int	chars_ft;
// 	int	chars;

// 	chars_ft = 0;
// 	chars = 0;
// 	// Тест для %c
// 	chars_ft = ft_printf("Char: %c\n", 'A');
// 	printf("chars_ft: %i\n", chars_ft);
// 	chars = printf("Char: %c\n", 'A');
// 	printf("chars: %i\n\n", chars);
// 	// Тест для %s
// 	chars_ft = ft_printf("String: %s\n", "hello");
// 	printf("chars_ft: %i\n", chars_ft);
// 	chars = printf("String: %s\n", "hello");
// 	printf("chars: %i\n\n", chars);
// 	// Тест для %s с NULL
// 	chars_ft = ft_printf("String: %s\n", NULL);
// 	printf("chars_ft: %i\n", chars_ft);
// 	chars = printf("String: %s\n", (char *)NULL);
// 	printf("chars: %i\n\n", chars);
// 	// Тест для %p
// 	void *ptr = (void *)0x1234abcd;
// 	chars_ft = ft_printf("Pointer: %p\n", ptr);
// 	printf("chars_ft: %i\n", chars_ft);
// 	chars = printf("Pointer: %p\n", ptr);
// 	printf("chars: %i\n\n", chars);
// 	// Тест для %p с NULL
// 	chars_ft = ft_printf("Pointer: %p\n", NULL);
// 	printf("chars_ft: %i\n", chars_ft);
// 	chars = printf("Pointer: %p\n", NULL);
// 	printf("chars: %i\n\n", chars);
// 	// Тест для %d
// 	chars_ft = ft_printf("Decimal: %d\n", -42);
// 	printf("chars_ft: %i\n", chars_ft);
// 	chars = printf("Decimal: %d\n", -42);
// 	printf("chars: %i\n\n", chars);
// 	// Тест для %i
// 	chars_ft = ft_printf("Integer: %i\n", 42);
// 	printf("chars_ft: %i\n", chars_ft);
// 	chars = printf("Integer: %i\n", 42);
// 	printf("chars: %i\n\n", chars);
// 	// Тест для %u
// 	chars_ft = ft_printf("Unsigned: %u\n", 4294967295U);
// 	printf("chars_ft: %i\n", chars_ft);
// 	chars = printf("Unsigned: %u\n", 4294967295U);
// 	printf("chars: %i\n\n", chars);
// 	// Тест для %x
// 	chars_ft = ft_printf("Hex lowercase: %x\n", 255);
// 	printf("chars_ft: %i\n", chars_ft);
// 	chars = printf("Hex lowercase: %x\n", 255);
// 	printf("chars: %i\n\n", chars);
// 	// Тест для %x с отрицательным числом
// 	chars_ft = ft_printf("Hex lowercase: %x\n", -1);
// 	printf("chars_ft: %i\n", chars_ft);
// 	chars = printf("Hex lowercase: %x\n", -1);
// 	printf("chars: %i\n\n", chars);
// 	// Тест для %X
// 	chars_ft = ft_printf("Hex uppercase: %X\n", 255);
// 	printf("chars_ft: %i\n", chars_ft);
// 	chars = printf("Hex uppercase: %X\n", 255);
// 	printf("chars: %i\n\n", chars);
// 	// Тест для %%
// 	chars_ft = ft_printf("Percent: %%\n");
// 	printf("chars_ft: %i\n", chars_ft);
// 	chars = printf("Percent: %%\n");
// 	printf("chars: %i\n\n", chars);
// 	return (0);
// 	}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		total_printed;
	int		spec_printed;

	va_start(args, s);
	i = 0;
	total_printed = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] && s[i + 1] != '\n')
		{
			spec_printed = ft_print_arg(args, s[i + 1]);
			if (spec_printed == -1)
				return (-1);
			total_printed += spec_printed;
			i += 2;
			continue ;
		}
		write(1, &s[i], 1);
		i++;
		total_printed++;
	}
	va_end(args);
	return (total_printed);
}

int	ft_print_arg(va_list args, char c)
{
	int	printed_chars;

	printed_chars = 0;
	if (c == 'c' || c == '%')
		return (ft_print_char(args, c));
	if (c == 's')
		return (ft_print_str(args));
	if (c == 'd' || c == 'i')
		return (ft_print_int_dec(args));
	if (c == 'p' || c == 'x' || c == 'X')
		return (ft_hex_sort(args, c));
	if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	return (printed_chars);
}

int	ft_hex_sort(va_list args, char c)
{
	int		printed_chars;
	char	*base_up;
	char	*base_low;

	printed_chars = 0;
	base_up = "0123456789ABCDEF";
	base_low = "0123456789abcdef";
	if (c == 'p')
		return (ft_ptr_print(va_arg(args, void *), base_low));
	if (c == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), base_low));
	if (c == 'X')
		return (ft_putnbr_hex(va_arg(args, unsigned int), base_up));
	return (printed_chars);
}

int	ft_ptr_print(void *ptr, char *base)
{
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	return (ft_putnbr_hex((uintptr_t)ptr, base) + 2);
}

int	ft_putnbr_hex(uintptr_t nbr, char *base)
{
	char	digit;
	int		printed_chars;

	printed_chars = 0;
	if (nbr >= 16)
		printed_chars += ft_putnbr_hex((nbr / 16), base);
	digit = base[(nbr % 16)];
	ft_putchar_fd(digit, 1);
	printed_chars++;
	return (printed_chars);
}
