/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asharafe <asharafe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:30:23 by asharafe          #+#    #+#             */
/*   Updated: 2025/09/20 21:26:45 by asharafe         ###   ########.fr       */
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

int	ft_print_str(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	len = (int)ft_strlen(str);
	return (len);
}

int	ft_print_char(va_list args, char c)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (c == '%')
		ft_putchar_fd('%', 1);
	return (1);
}

int	ft_print_int_dec(va_list args)
{
	char	*str;
	int		printed_chars;

	str = ft_itoa(va_arg(args, int));
	if (!str)
		return (-1);
	ft_putstr_fd(str, 1);
	printed_chars = (int)ft_strlen(str);
	free (str);
	return (printed_chars);
}

int	ft_putnbr_u(unsigned int nbr)
{
	char	digit;
	int		printed_chars;

	printed_chars = 0;
	if (nbr >= 10)
		printed_chars += ft_putnbr_u(nbr / 10);
	digit = (nbr % 10) + '0';
	ft_putchar_fd(digit, 1);
	printed_chars++;
	return (printed_chars);
}
