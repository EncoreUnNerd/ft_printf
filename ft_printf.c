/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhenin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:57:59 by mhenin            #+#    #+#             */
/*   Updated: 2024/10/28 15:58:01 by mhenin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putnbr_unsigned(unsigned int n)
{
	int	res;

	res = 0;
	if (n > 9)
		res += ft_putnbr_unsigned(n / 10);
	ft_putchar_fd('0' + (n % 10), 1);
	res++;
	return(res);
}

static int	cases(char l, va_list args)
{
	int	res;

	res = 0;
	if (l == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (l == 'd' || l == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (l == '%')
		ft_putchar_fd('%', 1);
	if (l == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (l == 'u')
		res += ft_putnbr_unsigned(va_arg(args, unsigned int));
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		res;
	va_list	args;

	res = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			res++;
		}
		else
		{
			format++;
			if (*format)
				res += cases(*format, args);
			else
				break ;
		}
		format++;
	}
	return (res);
}

int	main(void)
{
	void	*p;

	printf("\n%d\n", printf("test %s ", "test de fou"));
	printf("\n%d\n", ft_printf("test %s ", "elle follo"));
	return (0);
}
